// EDExcitSynapse.cc

// Local Includes
#include "EDExcitSynapse.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EDExcitSynapse ***********************************************/
/****************************************************************************************************************************************/

EDExcitSynapse::EDExcitSynapse()
{
	initSynapse();
}

EDExcitSynapse::EDExcitSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron): 
EDSynapse(_pNewPreNeuron,_pNewPostNeuron)
{
/*
	if (_pNewPreNeuron->getIndex() < 2500 && _pNewPostNeuron->getIndex() == 120)
	{
		cout << "Excit synapse index " << index << " is internal (" << _pNewPreNeuron->getIndex() << " " << _pNewPostNeuron->getIndex() << ")"<< endl;
	}
*/
	initSynapse();
}

EDExcitSynapse::~EDExcitSynapse()
{
#ifdef _TEST
	cout << "~EDExcitSynapse" << endl;
#endif
}

void EDExcitSynapse::initSynapse()
{
#ifdef _TEST
	cout << "Initing excit synapse" << endl;
#endif

#ifdef _FIXED_DELAY_MODE
	#ifdef _TOPOLOGICAL_DELAY_MODE
	delay=DELAY+returnTopologicalDelay();
	#else
	delay=DELAY;
	#endif
#endif
#ifdef _RANDOM_DELAY_MODE
	#ifdef _TOPOLOGICAL_DELAY_MODE
	delay=randomInt(DELAY)+1+returnTopologicalDelay();
	#else
	delay=randomInt(DELAY)+1;
	
	#endif
#endif

#ifdef _TEST
	cout << "Index" << getIndex() << " Delay: " << delay << endl;
	
#endif
/*
	if (getIndex() < 1000)
	{
		cout << "Index" << getIndex() << "Delay: " << delay << endl;
	}
*/

#ifdef _INITIAL_FIXED_WEIGHT_MODE
	weight=WEIGHT;
#endif
#ifdef _INITIAL_RANDOM_WEIGHT_MODE
	weight=WEIGHT*(1.0+1.0*randomSign()*randomProb());
#endif

#ifdef _TEST
	cout << "Weight: " << weight << endl;
#endif
}

#ifdef _ONLINE_LEARNING_MODE
void EDExcitSynapse::computeNewWeight()
{
	if (lastTimeOfPostSpike!=-1 && lastTimeOfPreSpike!=-1)
	{
		deltaWeight=excitTemporalWindow(lastTimeOfPostSpike-lastTimeOfPreSpike);

	#ifdef _TEST
		cout << "diffTime: " << lastTimeOfPostSpike-lastTimeOfPreSpike << " => deltaWeight: " << deltaWeight << endl;
	#endif

	#ifdef _EXCIT_MULTIPLICATIVE_STDP_MODE
	
		// Regle multiplicative de modification
		#ifdef _EXCIT_ALPHA_UPDATE_MODE
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = EXCIT_ALPHA*deltaWeight*(1.0 - weight);
			weight+=realDeltaWeight;

			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
				#endif
			#endif
		}
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = EXCIT_ALPHA*deltaWeight*weight;
			weight+=realDeltaWeight;

			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statDepression();
				#endif
			#endif
		}
		else if (deltaWeight < -1.0 || 1.0 < deltaWeight)
		{
			cerr << "Warning, deltaWeight has a wrong value " << deltaWeight << endl;
		}
		#else
			#ifdef _EXCIT_AUTO_SCALING_WEIGHT_MODE
		realDeltaWeight = deltaWeight*weight*(1.0-weight);
		weight+=realDeltaWeight;
			#else
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = deltaWeight*(1.0 - weight);
			weight+=realDeltaWeight;

				#ifdef _ASSEMBLY_STAT_MODE
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
					#endif
				#endif
		}
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = deltaWeight*weight;
			weight+=realDeltaWeight;

				#ifdef _ASSEMBLY_STAT_MODE
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statDepression();
					#endif
				#endif
		}
		else if (deltaWeight < -1.0 || 1.0 < deltaWeight)
		{
			cerr << "Warning, deltaWeight has a wrong value " << deltaWeight << endl;
		}
			#endif
		#endif
	#else
	
		// Regle additive de modification
		#ifdef _EXCIT_ALPHA_UPDATE_MODE
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = EXCIT_ALPHA*deltaWeight;
			weight+=realDeltaWeight;

			if (1.0 < weight)
			{
				weight = 1.0;
			}
			
			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
				#endif
			#endif
		}
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = EXCIT_ALPHA*deltaWeight;
			weight+=realDeltaWeight;

			if (weight < 0.0)
			{
				weight = 0.0;
			}
			
			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statDepression();
				#endif
			#endif
		}
		else if (deltaWeight < -1.0 || 1.0 < deltaWeight)
		{
			cerr << "Warning, deltaWeight has a wrong value " << deltaWeight << endl;
		}
		#else
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = deltaWeight;
			weight+=realDeltaWeight;

			if (1.0 < weight)
			{
				weight = 1.0;
			}
			
			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
				#endif
			#endif
		}
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = deltaWeight;
			weight+=realDeltaWeight;

			if (weight < 0.0)
			{
				weight = 0.0;
			}
			
			#ifdef _ASSEMBLY_STAT_MODE
				#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statDepression();
				#endif
			#endif
		}
		else if (deltaWeight < -1.0 || 1.0 < deltaWeight)
		{
			cerr << "Warning, deltaWeight has a wrong value " << deltaWeight << endl;
		}
	
		#endif
	#endif

	}
}
#endif

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
void EDExcitSynapse::statPotentiation()
{
	if(stater)
	{
		((ExcitSynapseStater*) stater)->statPotentiation(this);
	}
}
void EDExcitSynapse::statDepression()
{
	if(stater)
	{
		((ExcitSynapseStater*) stater)->statDepression(this);
	}
}

void EDExcitSynapse::statPreTemporalVariation(int temporalDeviation)
{
	if (stater)
	{
		((ExcitSynapseStater*) stater)->statPreTemporalVariation(temporalDeviation);
	}
}

void EDExcitSynapse::statPostTemporalVariation(int temporalDeviation)
{
	if (stater)
	{
		((ExcitSynapseStater*) stater)->statPostTemporalVariation(temporalDeviation);
	}
}

void EDExcitSynapse::initSynapseFiles(SynapseStater* ss)
{
	stater = (ExcitSynapseStater*) ss->getExcitSynapseStater();
	//stater = (ExcitSynapseStater*) ss;
}
	#endif
#endif
