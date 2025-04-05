// EDInhibSynapse.cc

// Local Includes
#include "EDInhibSynapse.h"

/****************************************************************************************************************************************/
/*************************************************** Methodes de la classe EDInhibSynapse ***********************************************/
/****************************************************************************************************************************************/


EDInhibSynapse::EDInhibSynapse()
{
	initSynapse();
}

EDInhibSynapse::EDInhibSynapse(Neuron* _pNewPreNeuron, Neuron* _pNewPostNeuron): EDSynapse(_pNewPreNeuron,_pNewPostNeuron)
{
/*
	if (_pNewPreNeuron->getIndex() < 2500 && _pNewPostNeuron->getIndex() == 750)
	{
		cout << "Inhib synapse index " << index << " is internal (" << _pNewPreNeuron->getIndex() << " " << _pNewPostNeuron->getIndex() << ")"<< endl;
	}
*/	
/*
	if (_pNewPreNeuron->getIndex() == 75 && _pNewPostNeuron->getIndex() < 2500)
	{
		cout << "Inhib synapse index " << index << " is internal (" << _pNewPreNeuron->getIndex() << " " << _pNewPostNeuron->getIndex() << ")"<< endl;
	}
*/
	initSynapse();
}

EDInhibSynapse::~EDInhibSynapse()
{
#ifdef _TEST
	cout << "~EDInhibSynapse" << endl;
#endif
}

void EDInhibSynapse::initSynapse()
{
#ifdef _TEST
	cout << "Initing inhib synapse" << endl;
#endif


#ifdef _TEST
	cout << "Initing excit synapse" << endl;
#endif

#ifdef _FIXED_DELAY_MODE
	#ifdef _TOPOLOGICAL_DELAY_MODE
	delay=INHIBITORY_DELAY+returnTopologicalDelay();
	#else
	delay=INHIBITORY_DELAY;
	#endif
#endif

#ifdef _RANDOM_DELAY_MODE
	#ifdef _TOPOLOGICAL_DELAY_MODE
	delay=randomInt(INHIBITORY_DELAY)+1+returnTopologicalDelay();
	#else
	delay=randomInt(INHIBITORY_DELAY)+1;
	
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
#ifdef _INITIAL_FIXED_INHIB_WEIGHT_MODE
	weight=-INHIB_WEIGHT;
#endif
#ifdef _INITIAL_RANDOM_INHIB_WEIGHT_MODE
	weight=-INHIB_WEIGHT*(1.0+1.0*randomSign()*randomProb());
#endif

#ifdef _TEST
	cout << "Weight: " << weight << endl;
#endif
}

#ifdef _ONLINE_LEARNING_MODE
void EDInhibSynapse::computeNewWeight()
{
	if (lastTimeOfPostSpike!=-1 && lastTimeOfPreSpike!=-1)
	{
		deltaWeight=inhibTemporalWindow(lastTimeOfPostSpike-lastTimeOfPreSpike);

		#ifdef _TEST
		cout << "diffTime: " << lastTimeOfPostSpike-lastTimeOfPreSpike << " => deltaWeight: " << deltaWeight << endl;
		#endif
		
		
		#ifdef _INHIB_MULTIPLICATIVE_STDP_MODE
		// Regle multiplicative
			#ifdef _INHIB_ALPHA_UPDATE_MODE
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = -INHIB_ALPHA*deltaWeight*(1.0 + weight);
			weight+=realDeltaWeight;

				#ifdef _ASSEMBLY_STAT_MODE
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
					#endif
				#endif
		}
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = INHIB_ALPHA*deltaWeight*weight;
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
		
				#ifdef _INHIB_AUTO_SCALING_WEIGHT_MODE
		weight+=deltaWeight*weight*(1.0+weight);
				#else
				
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = -deltaWeight*(1.0 + weight);
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
		
		// Regle additive
			#ifdef _INHIB_ALPHA_UPDATE_MODE
		//Potentiation
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = -INHIB_ALPHA*deltaWeight;
			weight+=realDeltaWeight;

			if (weight < -1.0)
			{
				weight = -1.0;
			}
			
				#ifdef _ASSEMBLY_STAT_MODE
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
					#endif
				#endif
		}
		// Depression
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = -INHIB_ALPHA*deltaWeight;
			weight+=realDeltaWeight;

			if (0.0 < weight)
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
		
		//Potentiation
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = -deltaWeight;
			weight+=realDeltaWeight;

			if (weight < -1.0)
			{
				weight = -1.0;
			}
			
				#ifdef _ASSEMBLY_STAT_MODE
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statPotentiation();
					#endif
				#endif
		}
		// Depression
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = -deltaWeight;
			weight+=realDeltaWeight;

			if (0.0 < weight)
			{
				weight = 0.0;
			}
			
				#ifdef _ASSEMBLY_STAT_MODE
					#ifdef _GLOBAL_SYNAPSE_STAT_MODE
			statDepression();
					#endif
				#endif
		}
		
			#endif
		#endif
		
		/*
		#ifdef _ALPHA_UPDATE_MODE
		if (0.0 < deltaWeight && deltaWeight <= 1.0)
		{
			realDeltaWeight = -INHIB_ALPHA*deltaWeight*(1.0 + weight);
			weight+=realDeltaWeight;

			#ifdef _ASSEMBLY_STAT_MODE
			statPotentiation();
			#endif
		}
		else if (-1.0 <= deltaWeight && deltaWeight < 0.0)
		{
			realDeltaWeight = INHIB_ALPHA*deltaWeight*weight;
			weight+=realDeltaWeight;

			#ifdef _ASSEMBLY_STAT_MODE
			statDepression();
			#endif
		}
		else if (deltaWeight < -1.0 || 1.0 < deltaWeight)
		{
			cerr << "Warning, deltaWeight has a wrong value " << deltaWeight << endl;
		} 
		#else
		
			#ifdef _AUTO_SCALING_WEIGHT_MODE
		weight+=deltaWeight*weight*(1.0+weight);
			#endif
		#endif
		*/

	}
}
#endif

#ifdef _ASSEMBLY_STAT_MODE
	#ifdef _GLOBAL_SYNAPSE_STAT_MODE
void EDInhibSynapse::statPotentiation()
{
	if(stater)
	{
		((InhibSynapseStater*) stater)->statPotentiation(this);
	}
}

void EDInhibSynapse::statDepression()
{
	if(stater)
	{
		((InhibSynapseStater*) stater)->statDepression(this);
	}
}

void EDInhibSynapse::statPreTemporalVariation(int temporalDeviation)
{
	if (stater)
	{
		((InhibSynapseStater*) stater)->statPreTemporalVariation(temporalDeviation);
	}
}

void EDInhibSynapse::statPostTemporalVariation(int temporalDeviation)
{
	if (stater)
	{
		((InhibSynapseStater*) stater)->statPostTemporalVariation(temporalDeviation);
	}
}

void EDInhibSynapse::initSynapseFiles(SynapseStater* ss)
{
	stater = (InhibSynapseStater*) ss->getInhibSynapseStater();
	//stater = (InhibSynapseStater*) ss;
}
	#endif
#endif

