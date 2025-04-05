// Pacman.cc

#include "Pacman.h"

/*********************************************************************************************/
/*                                                                                           */
/*                           Definitions des methodes de Pacman                              */
/*                                                                                           */
/*********************************************************************************************/

Pacman::Pacman(Zoo* newZoo): zoo(newZoo),menagerie(newZoo->getMenagerie()),dirMvt(STOP),dirVue(STOP),RootModule(PACMAN_NB_INPUTS,PACMAN_NB_OUTPUTS)
{
  	initComptMove();
	initSynchroBuffers();

	initInputBuffers();
	initOutputBuffers();
}

Pacman::~Pacman()
{
#ifdef _ZOO_TEST
	cerr << "In ~Pacman" << endl;
#endif
}

Pacman::Pacman(Pacman& pac): Individual((Individual&) pac), zoo(pac.zoo),menagerie(pac.menagerie),dirMvt(STOP),dirVue(STOP),RootModule((RootModule&) pac)
{
	//initTracer();

  	initComptMove();

	initSynchroBuffers();

	initInputBuffers();
	initOutputBuffers();
}

Chromosome* Pacman::clone()
{
#ifdef _ZOO_TEST
	cout << "Cloning pacman " << getTopoIndex() << endl;
#endif
	return new Pacman(*this);
}

void Pacman::initSynchroBuffers()
{
//#ifdef _GA_TEST
	cout << "*** Pacman " << getTopoIndex() << " *** Building synchroBuffers" << endl;
//#endif
	synchroBuffer = new OutputBuffer(CHROMO_BUFFER_SIZE,SYNCHRO_CHANNEL_TAG,EVO_NETWORK_MPI_ID);
}

void Pacman::setSynchroBuffers()
{
	// Pour le buffer vers EvoNetwork
	int comptGene=0;

	//if (synchroBuffers[0]->getSize() == tabGenes.size())
	if (synchroBuffer->getSize() == tabGenes.size())
	{
		vector<Gene*>::iterator it=tabGenes.begin();
		vector<Gene*>::iterator end=tabGenes.end();

		while (it!=end)
		{
			//(*synchroBuffers[0])[comptGene]=(int) ((Gene*) *it)->getValueAllele();
			(*synchroBuffer)[comptGene]=(int) ((Gene*) *it)->getValueAllele();
	#ifdef _MPI_TEST
			//cout << "synchroBuffer[0][" << comptGene << "] = " << (*synchroBuffers[0])[comptGene] << endl;
			cout << "synchroBuffer[" << comptGene << "] = " << (*synchroBuffers)[comptGene] << endl;
	#endif
			comptGene++;
			it++;
		}
	}
	else
	{
		//cerr << "Warning, imcompatible value of tabGenes (" << tabGenes.size() << ") and synchroBuffer[0] (" << synchroBuffers[0]->getSize() << ")" << endl;
		cerr << "Warning, incompatible value of tabGenes (" << tabGenes.size() << ") and synchroBuffer (" << synchroBuffer->getSize() << ")" << endl;
	}
	/*
	#ifdef _MPI_TEST
	cout << "Initing motor synchro buffer" << endl;
	#endif

	// Pour le buffer vers Moteur
	(*synchroBuffers[1])[0] = SKIP;
	*/
}

void Pacman::initInputBuffers()
{
  inputBuffers[0]=new InputBuffer(MOTOR_PATTERN_BUFFER_SIZE,MOVE_BODY_ON_LEFT_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
  inputBuffers[1]=new InputBuffer(MOTOR_PATTERN_BUFFER_SIZE,MOVE_BODY_ON_RIGHT_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
  inputBuffers[2]=new InputBuffer(MOTOR_PATTERN_BUFFER_SIZE,MOVE_HEAD_ON_LEFT_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
  inputBuffers[3]=new InputBuffer(MOTOR_PATTERN_BUFFER_SIZE,MOVE_HEAD_ON_RIGHT_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
}

void Pacman::initComptMove()
{
	comptMoveBodyOnLeft=0;
	comptMoveBodyOnRight=0;

	comptMoveHeadOnLeft=0;
	comptMoveHeadOnRight=0;
}

void Pacman::initOutputBuffers()
{
  // buffers destines aux classifieurs d'entree (ou ? la BAM)
  // Modalit? visuelle

  for (int i=FIRST_VISIO_CHANNEL_ETIQUETTE;i<LAST_VISIO_CHANNEL_ETIQUETTE;i++)
  {
	OutputBuffer* visioBuffer=new OutputBuffer(VISIO_BUFFER_SIZE,i,EVO_NETWORK_MPI_ID);
  	outputBuffers[i]=visioBuffer;
  }

  // Modalit? auditive
  outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]= new OutputBuffer(AUDIO_BUFFER_SIZE,LEFT_AUDIO_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
  outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]=new OutputBuffer(AUDIO_BUFFER_SIZE,RIGHT_AUDIO_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);

#ifdef _PREDATOR_CONTACT_PUNISHES_PACMAN_MODE
  // Buffer de punition
  outputBuffers[PUNISH_CHANNEL_ETIQUETTE]=new OutputBuffer(CONDITIONNING_BUFFER_SIZE,PUNISH_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
#endif

#ifdef _PREY_CONTACT_REWARDS_PACMAN_MODE
  // Buffer de r?compense
  outputBuffers[REWARD_CHANNEL_ETIQUETTE]=new OutputBuffer(CONDITIONNING_BUFFER_SIZE,REWARD_CHANNEL_ETIQUETTE,EVO_NETWORK_MPI_ID);
#endif
}

#ifdef _GRAPHICAL_DISPLAY_MODE
void Pacman::initPacmanDisplayer()
{
	displayer = new PacmanDisplayer();
}

void Pacman::freePacmanDisplayer()
{
	delete ((PacmanDisplayer*) displayer);
}
#endif

void Pacman::waitSynchro()
{
#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t1;
	time (&t1);
#endif

#ifdef _TEST_MODE
	int waitNbSteps=0;
	
	#ifdef _TRANSITION_STAT_MODE
	while (testSynchro() && waitNbSteps < EDNetwork::TRANSITION_TIME_LENGTH)
	//while (testSynchro() && waitNbSteps < 10)
	{
		receiveVoidInputs();
			#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
			#endif

		waitNbSteps++;
	}
	
	incrementEvalIndex();
	
		#ifdef _PHASE_TEST_MODE
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << " - in waitSynchro) to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
		#endif
		
		
	while (testSynchro() && waitNbSteps < NB_MAX_TEST_STEPS)
	//while (testSynchro() && waitNbSteps < 10)
	{
		receiveVoidInputs();
		#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
		#endif

		waitNbSteps++;
	}
	
	incrementEvalIndex();
		
	#else
	while (testSynchro() && waitNbSteps< NB_MAX_TEST_STEPS)
	{
		receiveVoidInputs();
		#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
		#endif
		waitNbSteps++;
	}
	
	incrementEvalIndex();
		
	#endif
#else
	#ifdef _BLOCKING_MODE

	int waitNbSteps=0;
	
		#ifdef _TRANSITION_STAT_MODE
	while (testSynchro() && waitNbSteps < EDNetwork::TRANSITION_TIME_LENGTH)
	//while (testSynchro() && waitNbSteps < 10)
	{
		receiveVoidInputs();
			#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
			#endif

		waitNbSteps++;
	}
	
			#ifdef _PHASE_TEST_MODE
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << ") to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
			#endif
	
	incrementEvalIndex();
		
	while (testSynchro() && waitNbSteps < 40)
	//while (testSynchro() && waitNbSteps < 10)
	{
		receiveVoidInputs();
			#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
			#endif

		waitNbSteps++;
	}
	
	incrementEvalIndex();
	
		#else
		
	while (testSynchro() && waitNbSteps < NB_MAX_TEST_STEPS)
	//while (testSynchro() && waitNbSteps < 40)
	//while (testSynchro() && waitNbSteps < 10)
	{
		receiveVoidInputs();
			#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
			#endif

		waitNbSteps++;
	}
	
	incrementEvalIndex();
	
		#endif
	#else
	int waitNbSteps=0;

	while (testSynchro() && waitNbSteps < 4000)
	{
		receiveVoidInputs();
		#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
		#endif

		waitNbSteps++;
	}
	
	incrementEvalIndex();
	#endif
#endif

#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t2;
	time(&t2);

	cout << "*** Pacman *** out of wait synchro loop for individual " << getTopoIndex() << " after " << waitNbSteps << " steps (" << difftime(t2,t1) << ")" << endl;
#else
	cout << "*** Pacman *** out of wait synchro loop for individual " << getTopoIndex() << " after " << waitNbSteps << " steps" << endl;
#endif

}


void Pacman::receiveInputs()
{
#ifdef _ZOO_TEST
	cout << "*** Pacman *** entering receiveInputs" << endl;
#endif
	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (!inputBuffers[i]->getActive())
			{
				// On teste si un nouvel input peut etre recu
				inputBuffers[i]->receiveInput();
			}
		}
	}
}

void Pacman::integrateInputs()
{
	for (int j=0;j<nbInputBuffers;j++)
	{
		if (inputBuffers[j]->getFlag())
		{
			if (inputBuffers[j]->isActive())
			{
				switch (j)
				{
					case 0:
					{
#ifdef _MPI_TEST
						cout << "*** Motor *** receiving BODY on LEFT from ***BAM***" << endl;
#endif
						if (inputBuffers[j]->getSize()==MOTOR_PATTERN_BUFFER_SIZE)
						{
							for (int i=0;i<MOTOR_PATTERN_BUFFER_SIZE;i++)
							{
#ifdef _BLOCKING_MODE
								for (int k=0;k<(int) (*inputBuffers[j])[i];k++)
								{
									comptMoveBodyOnLeft++;
								}
#else
								if ((*inputBuffers[j])[i]==1.0)
								{
									comptMoveBodyOnLeft++;
								}
#endif
							}

						}
						else cerr << " Motor  Error: message incompatible with MOTOR_PATTERN_BUFFER_SIZE" << endl;

						((InputBuffer*) inputBuffers[0])->freeActive();

						break;
					}
					case 1:
					{
#ifdef _MPI_TEST
						cout << "*** Motor *** receiving BODY on RIGHT from ***BAM***" << endl;
#endif
						if (inputBuffers[j]->getSize()==MOTOR_PATTERN_BUFFER_SIZE)
						{
							for (int i=0;i<MOTOR_PATTERN_BUFFER_SIZE;i++)
							{
#ifdef _BLOCKING_MODE
								for (int k=0;k<(int) (*inputBuffers[j])[i];k++)
								{
									comptMoveBodyOnRight++;
								}
#else
								if ((*inputBuffers[j])[i]==1.0)
								{
									comptMoveBodyOnRight++;
								}
#endif
							}
						}
						else cerr << " Motor  Error: message incompatible with MOTOR_PATTERN_BUFFER_SIZE" << endl;

						((InputBuffer*) inputBuffers[1])->freeActive();

						break;
					}
					case 2:
					{
#ifdef _MPI_TEST
						cout << "*** Motor *** receiving HEAD on LEFT from ***BAM***" << endl;
#endif
						if (inputBuffers[j]->getSize()==MOTOR_PATTERN_BUFFER_SIZE)
						{
							for (int i=0;i<MOTOR_PATTERN_BUFFER_SIZE;i++)
							{
#ifdef _BLOCKING_MODE
								for (int k=0;k<(int) (*inputBuffers[j])[i];k++)
								{
									comptMoveHeadOnLeft++;
								}
#else
								if ((*inputBuffers[j])[i]==1.0)
								{
									comptMoveHeadOnLeft++;
								}
#endif
							}

						}
						else cerr << " Motor Error: message incompatible with MOTOR_PATTERN_BUFFER_SIZE" << endl;

						((InputBuffer*) inputBuffers[2])->freeActive();

						break;
					}
					case 3:
					{
#ifdef _MPI_TEST
						cout << "*** Motor *** receiving HEAD on RIGHT from ***BAM***" << endl;
#endif
						if (inputBuffers[j]->getSize()==MOTOR_PATTERN_BUFFER_SIZE)
						{
							for (int i=0;i<MOTOR_PATTERN_BUFFER_SIZE;i++)
							{
#ifdef _BLOCKING_MODE
								for (int k=0;k<(int) (*inputBuffers[j])[i];k++)
								{
									comptMoveHeadOnRight++;
								}
#else
								if ((*inputBuffers[j])[i]==1.0)
								{
									comptMoveHeadOnRight++;
								}
#endif
							}
						}
						else cerr << " Motor Error: message incompatible with MOTOR_PATTERN_BUFFER_SIZE" << endl;

						((InputBuffer*) inputBuffers[3])->freeActive();

						break;
					}
					default:
					{
						cerr << "Motor Error: recus[" << j << "] > " << nbInputBuffers << endl;
						break;
					}
				}
			}
		}
	}
}

void Pacman::integrateOutputs()
{
#ifdef _GRAPHICAL_DISPLAY_MODE
	((PacmanDisplayer*) displayer)->cleanDisplay();
#endif
	bool visioFlag=1;
	bool audioFlag=1;

	for (int i=0;i<nbOutputBuffers;i++)
	{
#ifdef _MPI_TEST
		cout << "*** Pacman *** Output Buffer " << i << " " << outputBuffers[i]->getFlag() << endl;;
#endif
		if (outputBuffers[i]->getFlag())
		{
			if (outputBuffers[i]->isActive())
			{
				if(FIRST_VISIO_CHANNEL_ETIQUETTE<=i && i<LAST_VISIO_CHANNEL_ETIQUETTE)
				{
					visioFlag = 0;
				}
				else if(i==LEFT_AUDIO_CHANNEL_ETIQUETTE || i==RIGHT_AUDIO_CHANNEL_ETIQUETTE)
				{
					audioFlag = 0;
				}
			}
		}
	}
#ifdef _NO_MOVE_MODE
	#ifdef _BIMODAL_TEST_MODE
	if (visioFlag)
	{
		integrateVisioOutputs();
	}

	if (audioFlag)
	{
		integrateAudioOutputs();
	}
	#else
		#ifdef _VISIO_TEST_MODE
	if (visioFlag)
	{
		integrateVisioOutputs();
	}
		#else
			#ifdef _AUDIO_TEST_MODE
	if (audioFlag)
	{
		integrateAudioOutputs();
	}
			#endif
		#endif
	#endif
#else
	if (visioFlag)
	{
		integrateVisioOutputs();
	}

	if (audioFlag)
	{
		integrateAudioOutputs();
	}
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
	((PacmanDisplayer*) displayer)->flushDisplay();
#endif

}

void Pacman::sendOutputs()
{
	for (int i=0;i<nbOutputBuffers;i++)
	{
#ifdef _MPI_TEST
		cout << "*** Pacman *** Output Buffer " << i << " " << outputBuffers[i]->getFlag() << endl;;
#endif
		if (outputBuffers[i]->getFlag())
		{
			if (outputBuffers[i]->getActive())
			{
				outputBuffers[i]->sendOutput();
			}
		}
	}
}

void Pacman::getPosition(int & x,int & y)
{
	int lignes,colonnes;
	zoo->getTaille(lignes,colonnes);

	for(int i=0;i<lignes;i++)
	{
		for(int j=0;j<colonnes;j++)
		{
			if((*zoo)(i,j)=='0')
			{
				x=i;
				y=j;
				return;
			}
		}
	}

	cerr<< "pacman non trouve dans le zoo"<<endl;

	x=-1;
	y=-1;
	return;
}

Direction Pacman::getDirVue()
{
	return dirVue;
}

Direction Pacman::getDirMvt()
{
	return dirMvt;
}

#ifdef _RUN_MODE

void Pacman::runPacman()
{
#ifdef _MPI_TEST
	cerr << "*** Pacman *** receiving inputs" << endl;
#endif
	receiveInputs();
#ifdef _MPI_TEST
	cerr << "*** Pacman *** integrate inputs" << endl;
#endif
	integrateInputs();
#ifdef _MPI_TEST
	cerr << "*** Pacman *** run one step" << endl;
#endif
	runOneStep();
#ifdef _MPI_TEST
	cerr << "*** Pacman *** integrating outputs" << endl;
#endif
	integrateOutputs();
#ifdef _MPI_TEST
	cerr << "*** Pacman *** sending outputs" << endl;
#endif
	sendOutputs();
}

void Pacman::runOneStep()
{
		// Modification des directions relatives en fonction des compteurs

	// Pour la direction de mouvement (dirBody)
	if (MIN_ACTIVITY_RATIO<((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE)
	{
		if (MIN_ACTIVITY_RATIO-((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE<MIN_DIFF_ACTIVITY_RATIO)
		{
//#ifdef _ZOO_TEST
			cerr << "*** Motor *** sending BODY GO_AHEAD to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cerr << "*** Pacman *** integrating body GO_AHEAD" << endl;
#endif
			zoo->avancer(this);

		}
		else
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending BODY TURN_LEFT to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating body TURN_LEFT " << endl;
#endif
			//(*zoo)->avancer();
			dirMvt=static_cast<Direction>((dirMvt+3)%4);
			dirVue=static_cast<Direction>((dirVue+3)%4);

			zoo->tourner(this);
		}

		comptMoveBodyOnLeft=0;
		comptMoveBodyOnRight=0;
	}
	else if (MIN_ACTIVITY_RATIO<((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE)
	{
		if (MIN_ACTIVITY_RATIO-((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE<MIN_DIFF_ACTIVITY_RATIO)
		{
//#ifdef _ZOO_TEST
			cerr << "*** Motor *** sending BODY GO_AHEAD to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cerr << "*** Pacman *** integrating body GO_AHEAD" << endl;
#endif
			zoo->avancer(this);

		}
		else
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending BODY TURN_RIGHT to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating body TURN_RIGHT " << endl;
#endif
			//(*zoo)->avancer();
			dirMvt=static_cast<Direction>((dirMvt+1)%4);
			dirVue=static_cast<Direction>((dirVue+1)%4);

			zoo->tourner(this);
		}

		comptMoveBodyOnLeft=0;
		comptMoveBodyOnRight=0;
	}
#ifdef _ZOO_TEST
	else cout << "No BODY move: " << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE << " " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE << endl;
#endif

	// Pour la direction de la tete (dirHead)
	if (MIN_ACTIVITY_RATIO<((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE)
	{
		if (MIN_ACTIVITY_RATIO-((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE<MIN_DIFF_ACTIVITY_RATIO)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD GO_AHEAD to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head GO_AHEAD " << endl;
#endif
			dirVue=dirMvt;

		}
		else
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD TURN_LEFT to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head TURN_LEFT " << endl;
#endif
			dirVue=static_cast<Direction>((dirVue+3)%4);

		}

		comptMoveHeadOnLeft=0;
		comptMoveHeadOnRight=0;

	}
	else if (MIN_ACTIVITY_RATIO<((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE)
	{
		if (MIN_ACTIVITY_RATIO-((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE<MIN_DIFF_ACTIVITY_RATIO)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD GO_AHEAD to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head GO_AHEAD " << endl;
#endif
			dirVue=dirMvt;

		}
		else
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD TURN_RIGHT to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head TURN_RIGHT " << endl;
#endif
			dirVue=static_cast<Direction>((dirVue+1)%4);

		}

		comptMoveHeadOnLeft=0;
		comptMoveHeadOnRight=0;

	}
#ifdef _ZOO_TEST
	else cout << "No HEAD move: " << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE << " " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
	// On affiche le nouveau pacman
	((ZooDisplayer*) zoo->displayer)->displayDirMvt(this);
	((ZooDisplayer*) zoo->displayer)->displayDirVue(this);

	// on rafraichit
	((ZooDisplayer*) zoo->displayer)->flushDisplay();

	#ifdef _SAVE_ZOO_DISPLAY_MODE
	for (int i=0;i<INTER_WAVE_PERIOD;i++)
	{
		((ZooDisplayer*) zoo->displayer)->saveZooDisplayer(INTER_WAVE_PERIOD+10*INTER_WAVE_PERIOD+nbSteps*INTER_WAVE_PERIOD+i);
	}
	#endif
#endif
}

void Pacman::run()
{
	//#ifdef _ZOO_TEST
	cout << "*** Pacman *** entering main loop for individual " << getTopoIndex() << endl;
	//#endif

	#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t1;
	time (&t1);
	#endif

	initStats();

	initIndividualFiles();

	#ifdef _CONDITIONNING_MODE
	// Initialisation du niveau de vie du pacman
	lifeLevel=INITIAL_LIFE_LEVEL;
	initFitness();
	#endif

	/*
	//#ifdef _ZOO_TEST
	cout << "*** Pacman *** Zoo init for evaluation " << getEvalIndex() << endl;
	//#endif
	zoo->initZoo(LEVEL);
	
	//#ifdef _ZOO_TEST
	cout << "Zoo initZoo for evaluation " << getEvalIndex() << endl;
	//#endif
	*/
	// Prends a l'initilisation une valeur aleatoire
	#if (NB_EVALUATIONS == 4)
	dirMvt=static_cast<Direction>(getEvalIndex());
	dirVue=static_cast<Direction>(dirMvt);
	#else
	dirMvt=static_cast<Direction>(randomInt(STOP));
	dirVue=static_cast<Direction>(dirMvt);
	#endif

	initNbSteps();

	while(!zoo->mort((Pacman*) this) && nbSteps<NB_MAX_STEPS && testSynchro())
	{
#ifdef _MPI_TEST
		cerr << "*** Pacman *** main loop for individual " << getTopoIndex() << " at step " << nbSteps << endl;
#endif
		// On envoit les entr?es et on recoit les sorties du pacman
		runPacman();

#ifdef _MPI_TEST
		cerr << "*** Pacman *** moving animal at step " << nbSteps << endl;
#endif
		// on fait bouger les animaux
		zoo->vivre((Pacman*) this);

		nbSteps++;
#ifdef _BLOCKING_MODE
		lifeLevel-=2;
#else
		if (nbSteps%INTER_WAVE_PERIOD==0)
		{
			lifeLevel-=2;
		}
#endif
	}

	cout << "*** Pacman *** out of main loop for individual " << getTopoIndex() << " after " << nbSteps << endl;

	/*
	//#ifdef _ZOO_TEST
	cout << "*** Pacman *** delete Zoo" << endl;
	//#endif
	((Zoo*) zoo)->deleteZoo();
	*/
//#ifdef _MPI_TEST
	cout << "*** Pacman *** ending Individual Files" << endl;
//#endif

	endIndividualFiles();

	#ifdef _INDIVIDUAL_TRACE_MODE
		#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t2;
	time(&t2);
	// On ecrit les stats comportementales du pacman
	ecrireStats(difftime(t2,t1));
		#endif
		#ifndef _REAL_TIME_OF_COMPUTING_MODE
	// On ecrit les stats comportementales du pacman
	ecrireStats();
		#endif
	#endif
}

void Pacman::initStats()
{
	nbMvtsTous=0;
	nbMvtAvants=0;

	// Reinitilisation du fitness
	nbPacgums=0;
	nbPreys=0;
}


	#ifdef _REAL_TIME_OF_COMPUTING_MODE
void Pacman::ecrireStats(double diffTime)
{
	char nomFichier[50];

	sprintf(nomFichier,"Pacman%d_%d.sta",getEvoIndex(),getTopoIndex());
	ofstream f;
	f.open(nomFichier,fstream::app);

	f << "*** Evaluation " << getEvalIndex() << " ***" << endl;
	f << "mvts tous : " << getNbMvtsTous() << endl;
	f << "mvts avant : " << getNbMvtAvants() << endl;
	f << "pacgomes mangees : " << getNbPacgums() << endl;
	f << "gentils mangees : " << getNbPreys() << endl;
	f << "Time of Computing : " << diffTime << "(nb steps in zoo=" << getNbSteps() << ")" << endl;
	f << endl;

	f.close();
}
	#endif
	#ifndef _REAL_TIME_OF_COMPUTING_MODE
void Pacman::ecrireStats()
{
	char nomFichier[50];

	sprintf(nomFichier,"Pacman%d_%d.sta",getEvoIndex(),getTopoIndex());
	ofstream f;
	f.open(nomFichier,fstream::app);

	f << "*** Evaluation " << getEvalIndex() << " ***" << endl;
	f << "mvts tous : " << getNbMvtsTous() << endl;
	f << "mvts avant : " << getNbMvtAvants() << endl;
	f << "pacgomes mangees : " << getNbPacgums() << endl;
	f << "gentils mangees : " << getNbPreys() << endl;
	f << "nb steps in zoo=" << getNbSteps << endl;
	f << endl;

	f.close();
}
	#endif
#endif

#ifdef _CONDITIONNING_MODE
	#ifdef _PREDATOR_CONTACT_PUNISHES_PACMAN_MODE
void Pacman::sendPunish()
{
	if (!outputBuffers[PUNISH_CHANNEL_ETIQUETTE]->getActive() && outputBuffers[PUNISH_CHANNEL_ETIQUETTE]->getFlag())
	{
		// Construit un objet plein (toutes les valeurs ? 1.0)
		ObjetSensitif* obj = new ObjetSensitif(CONDITIONNING_BUFFER_SIZE);

			#ifdef _MPI_TEST
		cout << "*** Pacman *** sending PUNISH to ***BAM***" << endl;
			#endif
		outputBuffers[PUNISH_CHANNEL_ETIQUETTE]->integrateOutput(*obj);
		outputBuffers[PUNISH_CHANNEL_ETIQUETTE]->sendOutput();
		delete(obj);
	}
	else cerr << "*** Pacman *** unable to send punish, busy buffer " << PUNISH_CHANNEL_ETIQUETTE << endl;
}
	#endif

	#ifdef _PREY_CONTACT_REWARDS_PACMAN_MODE
void Pacman::sendReward()
{
	if (!outputBuffers[REWARD_CHANNEL_ETIQUETTE]->getActive() && outputBuffers[REWARD_CHANNEL_ETIQUETTE]->getFlag())
	{
		// Construit un objet plein (toutes les valeurs ? 1.0)
		ObjetSensitif* obj = new ObjetSensitif(CONDITIONNING_BUFFER_SIZE);

			#ifdef _MPI_TEST
		cout << "*** Pacman *** sending REWARD to ***BAM***" << endl;
			#endif
		outputBuffers[REWARD_CHANNEL_ETIQUETTE]->integrateOutput(*obj);
		outputBuffers[REWARD_CHANNEL_ETIQUETTE]->sendOutput();
		delete(obj);
	}
	else cerr << "*** Pacman *** unable to send reward, busy buffer " << REWARD_CHANNEL_ETIQUETTE << endl;

}
	#endif

void Pacman::sendRandomReward()
{
	if (!outputBuffers[REWARD_CHANNEL_ETIQUETTE]->getActive() && outputBuffers[REWARD_CHANNEL_ETIQUETTE]->getFlag())
	{
		// Construit un objet plein (toutes les valeurs ? 1.0)
		ObjetSensitif* obj = new ObjetSensitif(CONDITIONNING_BUFFER_SIZE);

		obj->brouiller(1.0);

		#ifdef _MPI_TEST
		cout << "*** Pacman *** sending RANDOMREWARD to ***BAM***" << endl;
		#endif
		outputBuffers[REWARD_CHANNEL_ETIQUETTE]->integrateOutput(*obj);
		outputBuffers[REWARD_CHANNEL_ETIQUETTE]->sendOutput();
		delete(obj);
	}
	else cerr << "*** Pacman *** unable to send reward, busy buffer " << REWARD_CHANNEL_ETIQUETTE << endl;
}
#endif

void Pacman::integrateBirthFlash()
{
	cout << "Pacman initing birth flash" << endl;

	cout << "Pacman testing synchro" << endl;
	testSynchro();
	//initEvalIndex();
	
	#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t1;
	time (&t1);
	#endif

	#ifdef _BLOCKING_MODE
		#ifdef _GRAPHICAL_DISPLAY_MODE
	((PacmanDisplayer*) displayer)->cleanDisplay();
		#endif
		
	for (int i=0;i<nbOutputBuffers;i++)
	{
		#ifdef _MPI_TEST
		cout << "*** Pacman *** Output Buffer " << i << " " << outputBuffers[i]->getFlag() << endl;;
		#endif
		if (outputBuffers[i]->getFlag())
		{
			if (!outputBuffers[i]->getActive())
			{
		#ifdef _MPI_TEST
				cout << "*** Pacman *** Initing Buffer " << i << endl;
		#endif
				if(FIRST_VISIO_CHANNEL_ETIQUETTE<=i && i<LAST_VISIO_CHANNEL_ETIQUETTE)
				{
		#ifdef _MPI_TEST
					cout << "*** Pacman *** Initing Visio Buffer " << i << endl;
		#endif
					Image* img = new Image(outputBuffers[i]->getSize());
					//outputBuffers[i]->freeActive();
/*
#ifdef _GRAPHICAL_DISPLAY_MODE
					cout << "*** Pacman *** displaying seen birth flash in buffer " << i << endl;
					((PacmanDisplayer*) displayer)->setObjetAVoir(img,0,0,i);
#endif
*/
		#ifdef _MPI_TEST
					cout << "*** Pacman *** integrating output in buffer " << i << endl;
		#endif
					outputBuffers[i]->integrateOutput(*img);
		#ifdef _MPI_TEST
					cout << "*** Pacman *** deleting seen animal in buffer " << i << endl;
		#endif
					delete(img);
		#ifdef _MPI_TEST
					cout << "*** Pacman *** after deleting seen animal in buffer " << i << endl;
		#endif
				}
				else if(i==LEFT_AUDIO_CHANNEL_ETIQUETTE || i==RIGHT_AUDIO_CHANNEL_ETIQUETTE)
				{
		#ifdef _MPI_TEST
					cout << "*** Pacman *** Initing Audio Buffer " << i-LEFT_AUDIO_CHANNEL_ETIQUETTE << endl;
		#endif
					Son* son = new Son(outputBuffers[i]->getSize());

					outputBuffers[i]->integrateOutput(*son);
					//outputBuffers[i]->sendOutput();
					//outputBuffers[i]->wait();
					//outputBuffers[i]->freeActive();
		#ifdef _GRAPHICAL_DISPLAY_MODE
					((PacmanDisplayer*) displayer)->setObjetAEntendre(son,0,0,i-LEFT_AUDIO_CHANNEL_ETIQUETTE);
		#endif
					delete(son);
				}
		#ifdef _CONDITIONNING_MODE
				else if (i==PUNISH_CHANNEL_ETIQUETTE || i==REWARD_CHANNEL_ETIQUETTE)
				{

			#ifdef _MPI_TEST
					cout << "*** Pacman *** Initing Conditionning Buffer " << i << endl;
			#endif
					ObjetSensitif* obj = new ObjetSensitif(outputBuffers[i]->getSize());

					outputBuffers[i]->integrateOutput(*obj);
					//outputBuffers[i]->sendOutput();
					//outputBuffers[i]->wait();
					//outputBuffers[i]->freeActive();
					delete(obj);
				}
		#endif
				else cerr << "Warning, " << i << " does not correspond to a known buffer index" << endl;
			}
		}
	}
		#ifdef _GRAPHICAL_DISPLAY_MODE
	((PacmanDisplayer*) displayer)->flushDisplay();
			
			#ifdef _SAVE_ZOO_DISPLAY_MODE	
	for (int i=0;i<INTER_WAVE_PERIOD;i++)
	{
		((ZooDisplayer*) zoo->displayer)->saveZooDisplayer(nbSteps*INTER_WAVE_PERIOD+i);
	}
			#endif	
		#endif

	sendOutputs();
	
		#ifdef _MPI_TEST
	cout << "*** Pacman *** receiving void inputs" << endl;
		#endif
	receiveVoidInputs();

	int waitNbSteps=0;
	
	
		#ifdef _TRANSITION_STAT_MODE
	//while (testSynchro() && waitNbSteps < 10)
	while (testSynchro() && waitNbSteps < NB_MAX_TEST_STEPS)
	{
		receiveVoidInputs();
			#ifdef _MPI_TEST
		cout << nbSteps << ": Waiting for inputs" << endl;
			#endif

		waitNbSteps++;
	}
		#else
	while (testSynchro() && waitNbSteps < 10)
	{
		receiveVoidInputs();
			#ifdef _MPI_TEST
		cout << nbSteps << ": Waiting for inputs" << endl;
			#endif

			#ifdef _SAVE_ZOO_DISPLAY_MODE	
		for (int i=0;i<INTER_WAVE_PERIOD;i++)
		{
			((ZooDisplayer*) zoo->displayer)->saveZooDisplayer(INTER_WAVE_PERIOD+waitNbSteps*INTER_WAVE_PERIOD+i);
		}
			#endif	
			
		waitNbSteps++;
	}
		#endif
	#else

	int waitNbSteps=0;

	while (testSynchro() && waitNbSteps < INTER_WAVE_PERIOD)
	{
		#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->cleanDisplay();
		#endif

		for (int i=0;i<nbOutputBuffers;i++)
		{
		#ifdef _MPI_TEST
			cout << "*** Pacman *** Output Buffer " << i << " " << outputBuffers[i]->getFlag() << endl;;
		#endif
			if (outputBuffers[i]->getFlag())
			{
				if (!outputBuffers[i]->getActive())
				{
		#ifdef _MPI_TEST
					cout << "*** Pacman *** Initing Buffer " << i << endl;
		#endif
					if(FIRST_VISIO_CHANNEL_ETIQUETTE<=i && i<LAST_VISIO_CHANNEL_ETIQUETTE)
					{
		#ifdef _MPI_TEST
						cout << "*** Pacman *** Initing Visio Buffer " << i << endl;
		#endif
						Image* img = new Image(outputBuffers[i]->getSize());
/*
	#ifdef _GRAPHICAL_DISPLAY_MODE
						cout << "*** Pacman *** displaying seen birth flash in buffer " << i << endl;
						((PacmanDisplayer*) displayer)->setObjetAVoir(img,0,0,i);
	#endif
*/
		#ifdef _MPI_TEST
						cout << "*** Pacman *** integrating output in buffer " << i << endl;
		#endif
						outputBuffers[i]->integrateOutput(*img);
		#ifdef _MPI_TEST
						cout << "*** Pacman *** deleting seen animal in buffer " << i << endl;
		#endif
						delete(img);
		#ifdef _MPI_TEST
						cout << "*** Pacman *** after deleting seen animal in buffer " << i << endl;
		#endif
					}
					else if(i==LEFT_AUDIO_CHANNEL_ETIQUETTE || i==RIGHT_AUDIO_CHANNEL_ETIQUETTE)
					{
		#ifdef _MPI_TEST
						cout << "*** Pacman *** Initing Audio Buffer " << i-LEFT_AUDIO_CHANNEL_ETIQUETTE << endl;
		#endif
						Son* son = new Son(outputBuffers[i]->getSize());
						outputBuffers[i]->integrateOutput(*son);
		#ifdef _GRAPHICAL_DISPLAY_MODE
						((PacmanDisplayer*) displayer)->setObjetAEntendre(son,0,0,i-LEFT_AUDIO_CHANNEL_ETIQUETTE);
		#endif
						delete(son);
					}
		#ifdef _CONDITIONNING_MODE
					else if (i==PUNISH_CHANNEL_ETIQUETTE || i==REWARD_CHANNEL_ETIQUETTE)
					{

			#ifdef _MPI_TEST
						cout << "*** Pacman *** Initing Conditionning Buffer " << i << endl;
			#endif
						ObjetSensitif* obj = new ObjetSensitif(outputBuffers[i]->getSize());
						outputBuffers[i]->integrateOutput(*obj);
						delete(obj);
					}
		#endif
					else cerr << "Warning, " << i << " does not correspond to a known buffer index" << endl;
				}
			}
		}
		#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->flushDisplay();
			
			#ifdef _SAVE_ZOO_DISPLAY_MODE	
		for (int i=0;i<INTER_WAVE_PERIOD;i++)
		{
			((ZooDisplayer*) zoo->displayer)->saveZooDisplayer(nbSteps*INTER_WAVE_PERIOD+i);
		}
			#endif
		#endif


		sendOutputs();
		#ifdef _MPI_TEST
		cout << "*** Pacman *** receiving void inputs" << endl;
		#endif
		receiveVoidInputs();

		waitNbSteps++;
	}

	while (testSynchro() && waitNbSteps < 10*INTER_WAVE_PERIOD)
	{
		receiveVoidInputs();
		#ifdef _MPI_TEST
		cout << nbSteps << ": Waiting for input s" << endl;
		#endif

		#ifdef _SAVE_ZOO_DISPLAY_MODE	
		for (int i=0;i<INTER_WAVE_PERIOD;i++)
		{
			((ZooDisplayer*) zoo->displayer)->saveZooDisplayer(INTER_WAVE_PERIOD+nbSteps*INTER_WAVE_PERIOD+i);
		}
		#endif
			
		waitNbSteps++;
	}

	#endif

	#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t2;
	time(&t2);

	cout << "*** Pacman *** out of birth flash loop for individual " << getTopoIndex() << " after " << waitNbSteps << " steps (" << difftime(t2,t1) << ")" << endl;
	#else
	cout << "*** Pacman *** out of birth flash loop for individual " << getTopoIndex() << " after " << waitNbSteps << " steps" << endl;
	#endif
}

bool Pacman::receiveVoidInputs()
{
	receiveInputs();

	bool active = 1;
	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (inputBuffers[i]->getActive())
			{
				inputBuffers[i]->freeActive();
				active = 0;
			}
		}
	}

	return active;
}
/*
void Pacman::integrateVoidInputs()
{
	for (int i=0;i<nbInputBuffers;i++)
	{
		if (inputBuffers[i]->getFlag())
		{
			if (inputBuffers[i]->getActive())
			{
				inputBuffers[i]->freeActive();
			}
		}
	}
}
*/
void Pacman::integrateVisioOutputs()
{
	int lignes,colonnes;
	zoo->getTaille(lignes,colonnes);

	int posX,posY;
	getPosition(posX,posY);

	// Correspond ? la direction de vue (direction des colomnes visuelles)
	int dirX,dirY;

	// correspond ? la direction perpendiculaire ? la dirVue (scan des colomnes)
	// Attention, on va de la gauche vers la droite par rapport ? la vue du pacman
	int dirPerX,dirPerY;


	switch(dirVue)
	{
		case HAUT:
		{
			dirX = -1;
			dirY = 0;

			dirPerX= 0;
			dirPerY= 1;
			break;
		}
		case BAS:
		{
			dirX = 1;
			dirY = 0;

			dirPerX = 0;
			dirPerY = -1;
			break;
		}
		case DROITE:
		{
			dirX = 0;
			dirY = 1;

			dirPerX = 1;
			dirPerY = 0;
			break;
		}
		case GAUCHE:
		{
			dirX = 0;
			dirY = -1;

			dirPerX = -1;
			dirPerY = 0;
			break;
		}
		default:
		{
			dirX=0;
			dirY=0;

			dirPerX=0;
			dirPerY=0;
			break;
		}
	}


	for (int i=0;i<NB_VISIO_INPUTS;i++)
	{
		int relativeColumnIndex=i-(NB_VISIO_INPUTS-1)/2;

		int xVu=0;
		int yVu=0;

	#ifdef _ZOO_TEST
		cout << "Scanning " << relativeColumnIndex << " column" <<endl;
	#endif

		for (int j=abs(relativeColumnIndex);j<VISIO_COLUMN_DEPTH;j++)
		{
			int dx=relativeColumnIndex*dirPerX+j*dirX;
			int dy=relativeColumnIndex*dirPerY+j*dirY;

	#ifdef _ZOO_TEST
			cout << "Scanning case [" << posX+dx << "][" << posY+dy << "]" << endl;
	#endif
				// si la case testee est hors du zoo, on passe
			if(((posX+dx)<0 || (posX+dx)>= lignes) || ((posY+dy) < 0||(posY+dy)>= colonnes))
			{
				break;
			}
			else if(((*zoo)(posX+dx,posY+dy)>='A') && ((*zoo)(posX+dx,posY+dy)<'X'))
			{
				xVu=dx;
				yVu=dy;
	#ifdef _ZOO_TEST
				cout << "Image found in column " << relativeColumnIndex << " at width " << j << endl;
	#endif
				break;
			}
			else if((*zoo)(posX+dx,posY+dy)=='X')
			{

				xVu=dx;
				yVu=dy;

				break;
			}

		}

		// si on voit rien, on renvoie NULL et on attribue -1 pour les coordonn?es absolues
		// de l'animal detect?.
		if(xVu==0 && yVu==0)
		{
	#ifdef _ZOO_TEST
			cout << "No image detected for column " << i << endl;
	#endif

	#ifdef _ZOO_TEST
			cerr<<"Display animal " << i << " on NetWindow"<<endl;
	#endif

	#ifdef _GRAPHICAL_DISPLAY_MODE
			((PacmanDisplayer*) displayer)->setObjetAVoir(0,0,0,i);
	#endif
		}
		// Vision d'un animal
		else if (((*zoo)(posX+xVu,posY+yVu)>='A') && ((*zoo)(posX+xVu,posY+yVu)<'X'))
		{

	#ifdef _ZOO_TEST
			cout << "Image detected in case " << " [" << posX+xVu << "][" << posY+yVu << "]" << endl;
	#endif

			Image* imageVue=static_cast<Image*>(menagerie[(*zoo)(posX+xVu,posY+yVu)-'A'].getModalite(0)->clone());

			//cerr << "Adding noise to pattern" << endl;
	#ifndef _NO_MOVE_MODE
			imageVue->brouiller(sqrt(static_cast<double>(xVu*xVu+yVu*yVu)));
	#endif
			// Envoi de l'image vue
	#ifdef _MPI_TEST
			cout << "*** Pacman *** sending detected image for column " << columnIndex << " to ***BAM***" << endl;
	#endif
			outputBuffers[i]->integrateOutput(*imageVue);

			// Affichage de l'image vue
	#ifdef _ZOO_TEST
			cerr<<"Display animal " << columnIndex << " on NetWindow"<<endl;
	#endif

	#ifdef _GRAPHICAL_DISPLAY_MODE
			((PacmanDisplayer*) displayer)->setObjetAVoir(imageVue,xVu,yVu,i);
	#endif
			delete(imageVue);
		}
		// Vision d'un mur
		else if ((*zoo)(posX+xVu,posY+yVu)=='X')
		{

	#ifdef _ZOO_TEST
			cout << "Wall detected in case " << " [" << posX+xVu << "][" << posY+yVu << "]" << endl;
	#endif
			Image* imageVue=static_cast<Image*>(menagerie[18].getModalite(0)->clone());
	#ifndef _NO_MOVE_MODE
			imageVue->brouiller(sqrt(static_cast<double>(xVu*xVu+yVu*yVu)));
	#endif
			// Envoi de l'image vue
	#ifdef _MPI_TEST
			cout << "*** Pacman *** sending detected image for column " << i << " to ***BAM***" << endl;
	#endif
			outputBuffers[i]->integrateOutput(*imageVue);

			// Affichage de l'image vue
	#ifdef _ZOO_TEST
			cerr<<"Display animal " << i << " on NetWindow"<<endl;
	#endif

	#ifdef _GRAPHICAL_DISPLAY_MODE
			((PacmanDisplayer*) displayer)->setObjetAVoir(imageVue,xVu,yVu,i);
	#endif
			delete(imageVue);
		}
	}
}

void Pacman::integrateVisioOutputs(int columnIndex)
{
	int lignes,colonnes;
	zoo->getTaille(lignes,colonnes);

	int posX,posY;
	getPosition(posX,posY);

	// Correspond ? la direction de vue (direction des colomnes visuelles)
	int dirX,dirY;

	// correspond ? la direction perpendiculaire ? la dirVue (scan des colomnes)
	// Attention, on va de la gauche vers la droite par rapport ? la vue du pacman
	int dirPerX,dirPerY;


	switch(dirVue)
	{
		case HAUT:
		{
			dirX = -1;
			dirY = 0;

			dirPerX= 0;
			dirPerY= 1;
			break;
		}
		case BAS:
		{
			dirX = 1;
			dirY = 0;

			dirPerX = 0;
			dirPerY = -1;
			break;
		}
		case DROITE:
		{
			dirX = 0;
			dirY = 1;

			dirPerX = 1;
			dirPerY = 0;
			break;
		}
		case GAUCHE:
		{
			dirX = 0;
			dirY = -1;

			dirPerX = -1;
			dirPerY = 0;
			break;
		}
		default:
		{
			dirX=0;
			dirY=0;

			dirPerX=0;
			dirPerY=0;
			break;
		}
	}

	int relativeColumnIndex=columnIndex-(NB_VISIO_INPUTS-1)/2;

	int xVu=0;
	int yVu=0;

#ifdef _ZOO_TEST
	cout << "Scanning " << relativeColumnIndex << " column" <<endl;
#endif

	for (int j=abs(relativeColumnIndex);j<VISIO_COLUMN_DEPTH;j++)
	{
		int dx=relativeColumnIndex*dirPerX+j*dirX;
		int dy=relativeColumnIndex*dirPerY+j*dirY;

#ifdef _ZOO_TEST
		cout << "Scanning case [" << posX+dx << "][" << posY+dy << "]" << endl;
#endif
			// si la case testee est hors du zoo, on passe
		if(((posX+dx)<0 || (posX+dx)>= lignes) || ((posY+dy) < 0||(posY+dy)>= colonnes))
		{
			break;
		}
		else if((((*zoo)(posX+dx,posY+dy)>='A') && ((*zoo)(posX+dx,posY+dy)<'X')))
		{
			xVu=dx;
			yVu=dy;
#ifdef _ZOO_TEST
			cout << "Image found in column " << relativeColumnIndex << " at width " << j << endl;
#endif
			break;
		}
		else if((*zoo)(posX+dx,posY+dy)=='X')
		{

			xVu=dx;
			yVu=dy;

			break;
		}

	}

	// si on voit rien, on renvoie NULL et on attribue -1 pour les coordonn?es absolues
	// de l'animal detect?.
	if(xVu==0 && yVu==0)
	{
#ifdef _ZOO_TEST
		cout << "No image detected for column " << columnIndex << endl;
#endif

#ifdef _ZOO_TEST
		cerr<<"Display animal " << columnIndex << " on NetWindow"<<endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->setObjetAVoir(0,0,0,columnIndex);
#endif
	}
	else if (((*zoo)(posX+xVu,posY+yVu)>='A') && ((*zoo)(posX+xVu,posY+yVu)<'X'))
	{

#ifdef _ZOO_TEST
		cout << "Image detected in case " << " [" << posX+xVu << "][" << posY+yVu << "]" << endl;
#endif

		Image* imageVue=static_cast<Image*>(menagerie[(*zoo)(posX+xVu,posY+yVu)-'A'].getModalite(0)->clone());

		//cerr << "Adding noise to pattern" << endl;
	#ifndef _NO_MOVE_MODE
		imageVue->brouiller(sqrt(static_cast<double>(xVu*xVu+yVu*yVu)));
	#endif
		// Envoi de l'image vue
#ifdef _MPI_TEST
		cout << "*** Pacman *** sending detected image for column " << columnIndex << " to ***BAM***" << endl;
#endif
		outputBuffers[columnIndex]->integrateOutput(*imageVue);

		// Affichage de l'image vue
#ifdef _ZOO_TEST
		cerr<<"Display animal " << columnIndex << " on NetWindow"<<endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->setObjetAVoir(imageVue,xVu,yVu,columnIndex);
#endif
		delete(imageVue);
	}
	else if ((*zoo)(posX+xVu,posY+yVu)=='X')
	{

#ifdef _ZOO_TEST
		cout << "Wall detected in case " << " [" << posX+xVu << "][" << posY+yVu << "]" << endl;
#endif
		Image* imageVue=static_cast<Image*>(menagerie[18].getModalite(0)->clone());
#ifndef _NO_MOVE_MODE
		imageVue->brouiller(sqrt(static_cast<double>(xVu*xVu+yVu*yVu)));
#endif
		// Envoi de l'image vue
#ifdef _MPI_TEST
		cout << "*** Pacman *** sending detected image for column " << columnIndex << " to ***BAM***" << endl;
#endif
		outputBuffers[columnIndex]->integrateOutput(*imageVue);

		// Affichage de l'image vue
#ifdef _ZOO_TEST
		cerr<<"Display animal " << columnIndex << " on NetWindow"<<endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->setObjetAVoir(imageVue,xVu,yVu,columnIndex);
#endif
		delete(imageVue);
	}
}

void Pacman::integrateAudioOutputs()
{
	int lignes,colonnes;
	zoo->getTaille(lignes,colonnes);

	int posX,posY;
	getPosition(posX,posY);

	int xEntendu=0;
	int yEntendu=0;

	int order=1;

#if (AUDIO_RANGE_DEPTH==5)
	while (order<=AUDIO_RANGE_DEPTH)
	{
		for (int i=-3;i<=3;i++)
		{
			for (int j=-3;j<=3;j++)
			{
				if (distMatrix[i+3][j+3]==order)
				{
	#ifdef _ZOO_TEST
					cout << "Scanning case [" << i << "][" << j << "] (order=" << order << ")" << endl;
	#endif

					// si la case testee est hors du zoo, on passe
					if( ((int)(posX+i) < 0) ||  ((int)(posX+i) >= lignes) || ((int)(posY+j) < 0) ||  ((int)(posY+j) >= colonnes) )
					{
						continue;
					}

					if((zoo(posX+i,posY+j)>='A') && (zoo(posX+i,posY+j)<'X'))
					{
						double random=randomProb();
						double dist=sqrt(static_cast<double>(i*i+j*j));

						if (random<=(3*sqrt(2.0)-dist)/(3*sqrt(2.0))*ANIMAL_EMITS_SOUND_PROB)
						{
	#ifdef _ZOO_TEST
							cout << "Sound detected in case " << " [" << posX+i << "][" << posY+j << "]" << endl;
	#endif
							xEntendu=i;
							yEntendu=j;
							break;
						}
					}
				}
			}
		}
		order++;
	}
#elif (AUDIO_RANGE_DEPTH==11)
	while (order<=AUDIO_RANGE_DEPTH)
	{
		for (int i=-4;i<=4;i++)
		{
			for (int j=-4;j<=4;j++)
			{
				if (distMatrix[i+4][j+4]==order)
				{
	#ifdef _ZOO_TEST
					cout << "Scanning case [" << i << "][" << j << "] (order=" << order << ")" << endl;
	#endif

					// si la case testee est hors du zoo, on passe
					if( ((int)(posX+i) < 0) ||  ((int)(posX+i) >= lignes) || ((int)(posY+j) < 0) ||  ((int)(posY+j) >= colonnes) )
					{
						continue;
					}

					if(((*zoo)(posX+i,posY+j)>='A') && ((*zoo)(posX+i,posY+j)<'X'))
					{
						double random=randomProb();
						double dist=sqrt(static_cast<double>(i*i+j*j));

						if (random<=(3*sqrt(2.0)-dist)/(3*sqrt(2.0))*ANIMAL_EMITS_SOUND_PROB)
						{
	#ifdef _ZOO_TEST
							cout << "Sound detected in case " << " [" << posX+i << "][" << posY+j << "]" << endl;
	#endif
							xEntendu=i;
							yEntendu=j;
							break;
						}
					}
				}
			}
		}
		order++;
	}
#endif

	if(xEntendu==0 && yEntendu==0)
	{
		// Pas de son à gauche
#ifdef _ZOO_TEST
		cout << "No sound detected" << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
		// Affichage du son
		((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,0);
#endif

		// Pas de son à droite
#ifdef _ZOO_TEST
		cout << "No sound detected" << endl;
#endif

#ifdef _GRAPHICAL_DISPLAY_MODE
		// Affichage du son
		((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,1);
#endif
	}
	else
	{

		//int leftHearX,leftHearY;
		//int rightHearX,rightHearY;

		switch(dirVue)
		{
			case HAUT:
			{
				/*
				leftHearX = 0;
				leftHearY = -1;

				rightHearX = 0;
				rightHearY = 1;
				*/
				if (yEntendu<0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Pas de son à droite
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID right sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,1);
			#endif
				}
				else if (yEntendu==0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu-rightHearX,yEntendu-rightHearY,1);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}
				else if (yEntendu>0)
				{
					// Pas de son à gauche
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif

			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID left hear sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif

			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,0);
			#endif

					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu-rightHearX,yEntendu-rightHearY,1);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}

				break;
			}
			case BAS:
			{
				/*
				leftHearX = 0;
				leftHearY = 1;

				rightHearX = 0;
				rightHearY = -1;
				*/
				if (yEntendu>0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Pas de son à droite
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID right sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,1);
			#endif
				}
				else if (yEntendu==0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu-leftHearX,yEntendu-leftHearY,0);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu-rightHearX,yEntendu-rightHearY,1);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}
				else if (yEntendu<0)
				{
					// Pas de son à gauche
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif

			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID left hear sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif

			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,0);
			#endif

					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}

				break;
			}
			case DROITE:
			{
				/*
				leftHearX = -1;
				leftHearY = 0;

				rightHearX = 1;
				rightHearY = 0;
				*/
				if (xEntendu<0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));

			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Pas de son à droite
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID right sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,1);
			#endif
				}
				else if (xEntendu==0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu-leftHearX,yEntendu-leftHearY,0);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu-rightHearX,yEntendu-rightHearY,1);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}
				else if (xEntendu>0)
				{
					// Pas de son à gauche
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif

			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID left hear sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif

			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,0);
			#endif

					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}

				break;
			}
			case GAUCHE:
			{
				/*
				leftHearX = 1;
				leftHearY = 0;

				rightHearX = -1;
				rightHearY = 0;
				*/
				if (xEntendu>0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu-leftHearX,yEntendu-leftHearY,0);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Pas de son à droite
			#ifdef _ZOO_TEST
					cout << "No sound detected" << endl;
			#endif
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID right sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,1);
			#endif
				}
				else if (xEntendu==0)
				{
					// Son à gauche
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille gauche
					Son* sonEntenduLeft=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double leftHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduLeft->brouiller(leftHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,xEntendu,yEntendu,0);
			#endif
					delete(sonEntenduLeft);


					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}
				else if (xEntendu<0)
				{
					// Pas de son à gauche
			#ifdef _ZOO_TEST
					cout << "No sound detected on left" << endl;
			#endif

			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending VOID left hear sound for column " << lateralityIndex << " to ***BAM***" << endl;
			#endif

			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					((PacmanDisplayer*) displayer)->setObjetAEntendre(0,0,0,0);
			#endif

					// Son à droite
			#ifdef _ZOO_TEST
					cout << "Sound detected on right in case " << " [" << posX+xEntendu << "][" << posY+yEntendu << "]" << endl;
			#endif
					// Calcul du son entendu par l'oreille droite
					Son* sonEntenduRight=static_cast<Son*>(menagerie[(*zoo)(posX+xEntendu,posY+yEntendu)-'A'].getModalite(1)->clone());
					double rightHearDist=sqrt(static_cast<double>((xEntendu*xEntendu)+(yEntendu*yEntendu)));
			#ifndef _NO_MOVE_MODE
					sonEntenduRight->brouiller(rightHearDist);
			#endif
					// Envoi du son
			#ifdef _MPI_TEST
					cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
			#endif
					outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
			#ifdef _GRAPHICAL_DISPLAY_MODE
					// Affichage du son
					//((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu-rightHearX,yEntendu-rightHearY,1);
					((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,xEntendu,yEntendu,1);
			#endif
					delete(sonEntenduRight);
				}

				break;
			}
			default:
			{
				break;
			}
		}

	}
}

#ifdef _TEST_MODE
	#ifdef _WAITING_PERIOD_TEST_MODE
void Pacman::waitPeriod()
{
	int waitNbSteps=0;

	while (testSynchro() && waitNbSteps < NB_MAX_TEST_STEPS)
	{
		receiveVoidInputs();
		#ifdef _MPI_TEST
		cout << waitNbSteps << ": Waiting for inputs" << endl;
		#endif

		waitNbSteps++;
	}
	
}
  	#endif
	
void Pacman::testOneStep()
{
	// Modification des directions relatives en fonction des compteurs

		// Modification des directions relatives en fonction des compteurs

	// Pour la direction de mouvement (dirBody)
	if (MIN_ACTIVITY_RATIO<=((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE || MIN_ACTIVITY_RATIO<=((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE)
	{
		if (abs(comptMoveBodyOnLeft-comptMoveBodyOnRight)/((double)MOTOR_PATTERN_BUFFER_SIZE)<MIN_DIFF_ACTIVITY_RATIO)
		{
//#ifdef _ZOO_TEST
			cerr << "*** Motor *** sending BODY GO_AHEAD to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
	#ifdef _ZOO_TEST
			cerr << "*** Pacman *** integrating body GO_AHEAD" << endl;
	#endif
			zoo->testAvancer(this);

		}
		else if (comptMoveBodyOnRight <= comptMoveBodyOnLeft)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending BODY TURN_LEFT to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
	#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating body TURN_LEFT " << endl;
	#endif
			//(*zoo)->avancer();
			dirMvt=static_cast<Direction>((dirMvt+3)%4);
			dirVue=static_cast<Direction>((dirMvt+3)%4);

			zoo->tourner(this);
		}
		else if (comptMoveBodyOnLeft <= comptMoveBodyOnRight)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending BODY TURN_RIGHT to ***Pacman*** with ";
			cout << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
	#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating body TURN_RIGHT " << endl;
	#endif
			//(*zoo)->avancer();
			dirMvt=static_cast<Direction>((dirMvt+1)%4);
			dirVue=static_cast<Direction>((dirMvt+1)%4);

			zoo->tourner(this);
		}
		else
		{
			cerr << "Warning, unable to handle countMoveBody " << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cerr << " & " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
			return;
		}

		comptMoveBodyOnLeft=0;
		comptMoveBodyOnRight=0;
	}
	#ifdef _ZOO_TEST
	else cout << "No BODY move: " << ((double) comptMoveBodyOnLeft)/MOTOR_PATTERN_BUFFER_SIZE << " " << ((double) comptMoveBodyOnRight)/MOTOR_PATTERN_BUFFER_SIZE << endl;
	#endif

	// Pour la direction de la tete (dirHead)
	if (MIN_ACTIVITY_RATIO<=((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE || MIN_ACTIVITY_RATIO<=((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE)
	{
		if (abs(comptMoveHeadOnLeft-comptMoveHeadOnRight)/((double) MOTOR_PATTERN_BUFFER_SIZE)<MIN_DIFF_ACTIVITY_RATIO)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD GO_AHEAD to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
	#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head GO_AHEAD " << endl;
	#endif
			dirVue=dirMvt;

		}
		else if (comptMoveHeadOnRight <= comptMoveHeadOnLeft)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD TURN_LEFT to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
	#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head TURN_LEFT " << endl;
	#endif
			dirVue=static_cast<Direction>((dirVue+3)%4);

		}
		else if (comptMoveHeadOnLeft <= comptMoveHeadOnRight)
		{
//#ifdef _ZOO_TEST
			cout << "*** Motor *** sending HEAD TURN_RIGHT to ***Pacman*** with ";
			cout << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cout << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
//#endif
	#ifdef _ZOO_TEST
			cout << "*** Pacman *** integrating head TURN_RIGHT " << endl;
	#endif
			dirVue=static_cast<Direction>((dirVue+1)%4);

		}
		else
		{
			cerr << "Warning, unable to handle countMoveHead " << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE;
			cerr << " & " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE  << endl;
			return;
		}

		comptMoveHeadOnLeft=0;
		comptMoveHeadOnRight=0;

	}
	#ifdef _ZOO_TEST
	else cout << "No HEAD move: " << ((double) comptMoveHeadOnLeft)/MOTOR_PATTERN_BUFFER_SIZE << " " << ((double) comptMoveHeadOnRight)/MOTOR_PATTERN_BUFFER_SIZE << endl;
	#endif

	#ifdef _GRAPHICAL_DISPLAY_MODE
	// On affiche le nouveau pacman
	((ZooDisplayer*) zoo->displayer)->displayDirMvt(this);
	((ZooDisplayer*) zoo->displayer)->displayDirVue(this);

	// on rafraichit
	((ZooDisplayer*) zoo->displayer)->flushDisplay();
			
		#ifdef _SAVE_ZOO_DISPLAY_MODE			
	for (int i=0;i < INTER_WAVE_PERIOD; i++)
	{
		((ZooDisplayer*) zoo->displayer)->saveZooDisplayer(INTER_WAVE_PERIOD+10*INTER_WAVE_PERIOD+nbSteps*INTER_WAVE_PERIOD+i);
	}
		#endif
		
	#endif

}

void Pacman::testPacman()
{
	cout << "*** Pacman *** entering test loop for individual " << getTopoIndex() << endl;

	#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t1;
	time (&t1);
	#endif

	int waitNbSteps = 0;
	
	while(!zoo->testMort((Pacman*) this) && waitNbSteps<NB_MAX_TEST_STEPS && testSynchro())
	{
		#ifdef _MPI_TEST
		cerr << "*** Pacman *** test loop for individual " << getTopoIndex() << " at step " << nbTestSteps << endl;
		#endif

		receiveInputs();

		integrateInputs();

		testOneStep();

		integrateOutputs();

		sendOutputs();

		waitNbSteps++;

		// Si le pacman n'est ni sorti du terrain, ni a mangé l'animal, alors on compte un mauvais comportement
		if (waitNbSteps== NB_MAX_TEST_STEPS)
		{
			statBadBehaviour();
			break;
		}
	}

	incrementEvalIndex();

	#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t2;
	time(&t2);
	#endif
	cout << "*** Pacman *** out of test " << getTestIndex() <<  " loop for individual " << getTopoIndex() << " after " << waitNbSteps << " steps (" << difftime(t2,t1) << ")" << endl;
}


void Pacman::test()
{
	initIndividualScore();

	#ifdef _ORDERED_TEST_MODE
	initTestIndex();

	while (getTestIndex() < NB_MAX_SCREENS)
	{
		//int animalIndex=randomInt(10);
		for (int i=0;i<4;i++)
		{
			zoo->initTestZoo(getTestIndex());

			cout << "Pacman entering test " << getTestIndex() << " with zoo " << getTestIndex()%NB_MAX_SCREENS << endl;



			initComptMove();

			dirMvt=static_cast<Direction>(i);
			dirVue=static_cast<Direction>(dirMvt);

	/*
			dirMvt=static_cast<Direction>(DROITE);
			dirVue=static_cast<Direction>(DROITE);
	*/
		#ifdef _GRAPHICAL_DISPLAY_MODE
			((ZooDisplayer*) zoo->displayer)->initDisplayer(zoo);
		#endif

			testPacman();

		#ifdef _WAITING_PERIOD_TEST_MODE
  			waitPeriod();
  		#endif

			zoo->deleteZoo();

			// Test, entouré de 2 periodes "à vide"
		#ifdef _PHASE_TEST_MODE
			if (getTestIndex() < NB_MAX_SCREENS)
			{
				//#ifdef _MPI_TEST
				cout << "*** Pacman *** sending void synchro to *** EDNetwork ***" << endl;
				//#endif
				sendVoidSynchro();
			}
		#endif
		}

		incrementTestIndex();
	}


	#else
	initTestIndex();

	while (getTestIndex() < NB_TESTED_ANIMALS)
	{
		#ifdef _RANDOM_TEST_MODE
		double random = randomProb();

		if (random < 0.5)
		{
			int animalIndex=randomInt(NB_MAX_PREYS);

			cout << "Pacman in prey test " << getTestIndex() << " with zoo " << animalIndex << endl;
			zoo->initTestZoo(animalIndex);
		}
		else if (0.5 <=random)
		{
			int animalIndex=randomInt(NB_MAX_PREDATORS);

			cout << "Pacman in predator test " << getTestIndex() << " with zoo " << animalIndex+NB_MAX_PREYS << endl;
			zoo->initTestZoo(animalIndex+NB_MAX_PREYS);

		}

		#else
			#ifdef _ALTERNATED_TEST_MODE
		if (getTestIndex()%2==0)
		{
			// Si pair, proie
			int animalIndex=randomInt(NB_MAX_PREYS);

			cout << "Pacman in prey test " << getTestIndex() << " with zoo " << animalIndex << endl;
			zoo->initTestZoo(animalIndex);
		}
		else
		{
			// Si impair, prédateur
			int animalIndex=randomInt(NB_MAX_PREDATORS);

			cout << "Pacman in predator test " << getTestIndex() << " with zoo " << animalIndex+NB_MAX_PREYS << endl;
			zoo->initTestZoo(animalIndex+NB_MAX_PREYS);

		}
			#else
		int animalIndex=randomInt(NB_MAX_PREDATORS+NB_MAX_PREYS);
		cout << "Pacman entering test " << getTestIndex() << " with zoo " << animalIndex << endl;

		zoo->initTestZoo(animalIndex);
			#endif
		#endif

		
		initComptMove();

		dirMvt=static_cast<Direction>(randomInt(4));
		dirVue=static_cast<Direction>(dirMvt);

/*
		dirMvt=static_cast<Direction>(DROITE);
		dirVue=static_cast<Direction>(DROITE);
*/
		#ifdef _GRAPHICAL_DISPLAY_MODE
		((ZooDisplayer*) zoo->displayer)->initDisplayer(zoo);
		#endif


		testPacman();


		#ifdef _WAITING_PERIOD_TEST_MODE
  		waitPeriod();
  		#endif
		
		zoo->deleteZoo();
	
		
		incrementTestIndex();
	
		// Test, entouré de 2 periodes "à vide"
		#ifdef _PHASE_TEST_MODE
		if (getTestIndex() < NB_TESTED_ANIMALS)
		{
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending void synchro to *** EDNetwork ***" << endl;
			//#endif
			sendVoidSynchro();
		}
		#endif

	}
	
	#endif
}


	#if (defined(_TEST_BEST_POPULATION_MODE) || defined (_TEST_RANDOM_POPULATION_MODE))
void Pacman::testAllZoo()
{
	initIndividualScore();

		#ifdef _MULTI_TEST_MODE
	
	initTestIndex();
	
	//while (getTestIndex() < NB_MULTI_TESTS+1 && )
	while (getTestIndex() < NB_MULTI_TESTS+1)
	{
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** integrating BirthFlash" << endl;
		//#endif
		integrateBirthFlash();
	
		//#ifdef _PHASE_TEST_MODE
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << "- after birth flash) to *** EDNetwork ***" << endl;
		//#endif
		sendVoidSynchro();
		//#endif
	
		//testSynchro();
			
		waitSynchro();
		
			#ifdef _PHASE_TEST_MODE
		// Test, entouré de 2 periodes "à vide"
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << "- after wait synchro 1) to *** EDNetwork ***" << endl;
		//#endif
		sendVoidSynchro();
			#endif
			
			#ifdef _TRANSITION_STAT_MODE
		while (getEvalIndex() < 2*(2*NB_TESTED_ANIMALS+1))
		{
			
			int animalIndex;
	
				#ifdef _ORDERED_TEST_MODE
			animalIndex=getEvalIndex()%menagerie.getTaille();
				#else
					#ifdef _RANDOM_TEST_MODE
			double random = randomProb();
	
			if (random < 0.5)
			{
	
				animalIndex=randomInt(menagerie.getTaille());
	
				while (menagerie[animalIndex].getPersonnalite() =! (Personnalite)GENTIL)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}
	
				cout << "Pacman in prey test " << getTestIndex() << " with zoo " << animalIndex << endl;
			}
			else if (0.5 <=random)
			{
				animalIndex=randomInt(menagerie.getTaille());
	
				while (menagerie[animalIndex].getPersonnalite() =! (Personnalite)MECHANT)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}
	
				cout << "Pacman in predator test " << getEvalIndex() << " with zoo " << animalIndex << endl;
	
			}
	
					#else
						#ifdef _ALTERNATED_TEST_MODE
			if (getEvalIndex()%2==0)
			{
				animalIndex=randomInt(menagerie.getTaille());
	
				while (menagerie[animalIndex].getPersonnalite() != (Personnalite)GENTIL)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}
	
				cout << "Pacman in prey test " << getEvalIndex() << " with zoo " << animalIndex << endl;
	
			}
			else
			{
				animalIndex=randomInt(menagerie.getTaille());
	
				while (menagerie[animalIndex].getPersonnalite() != (Personnalite)MECHANT)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}
	
				cout << "Pacman in predator test " << getEvalIndex() << " with zoo " << animalIndex << endl;
	
			}
						#else
			animalIndex=randomInt(menagerie.getTaille());
			cout << "Pacman entering test " << getEvalIndex() << " with zoo " << animalIndex << endl;
	
						#endif
					#endif
				#endif
	
			initComptMove();
			
				
				#ifdef _NO_MOVE_TEST_MODE
			testBestPacman(animalIndex);
				#else
			testPacman();
				#endif
			
				#ifdef _PHASE_TEST_MODE
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << " - after test) to *** EDNetwork ***" << endl;
			//#endif
			sendVoidSynchro();
				#endif
			
			waitSynchro();
			
				#ifdef _PHASE_TEST_MODE
			if (getEvalIndex() < 2*(2*NB_TESTED_ANIMALS+1))
			{
				//#ifdef _MPI_TEST
				cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << " - after wait synchro 1 - in eval loop) to *** EDNetwork ***" << endl;
				//#endif
				sendVoidSynchro();
			}
				#endif
		}
		
			#else
			
		while (getEvalIndex() < 2*NB_TESTED_ANIMALS+1)
		{
			
			int animalIndex;
	
				
				#ifdef _REPETITIVE_TEST_MODE	
					#ifdef _REPETITIVE_PREY_TEST_MODE 
			if (((Animal) menagerie[REPETITIVE_PREY_INDEX]).getPersonnalite() != (Personnalite) GENTIL)
			{
				cerr << "Warning, animal with index " << REPETITIVE_PREY_INDEX << " in menagerie is not a prey" << endl;
			}
			else
			{
				cout << "Pacman in prey test " << REPETITIVE_PREY_INDEX << " with animal " << menagerie[REPETITIVE_PREY_INDEX].getNomFR() << endl;
				animalIndex=REPETITIVE_PREY_INDEX;
			}
					#endif
					#ifdef _REPETITIVE_PREDATOR_TEST_MODE 
			if (((Animal) menagerie[REPETITIVE_PREDATOR_INDEX]).getPersonnalite() != (Personnalite) MECHANT)
			{
				cerr << "Warning, animal with index " << REPETITIVE_PREDATOR_INDEX << " in menagerie is not a predator" << endl;
			}
			else
			{
				cout << "Pacman in predator test " << REPETITIVE_PREDATOR_INDEX << " with animal " << menagerie[REPETITIVE_PREDATOR_INDEX].getNomFR() << endl;
				animalIndex=REPETITIVE_PREDATOR_INDEX;
			}	
					#endif		
					#ifdef _ALTERNATED_REPETITIVE_TEST_MODE
			if (getEvalIndex() == 3)
			{
				if (((Animal) menagerie[REPETITIVE_PREY_INDEX]).getPersonnalite() != (Personnalite) GENTIL)
				{
					cerr << "Warning, animal with index " << REPETITIVE_PREY_INDEX << " in menagerie is not a prey" << endl;
				}
				else
				{
					cout << "Pacman in prey test " << REPETITIVE_PREY_INDEX << " with animal " << menagerie[REPETITIVE_PREY_INDEX].getNomFR() << endl;
					animalIndex=REPETITIVE_PREY_INDEX;
				}
			}
			else if (getEvalIndex() == 1)
			{
				if (((Animal) menagerie[REPETITIVE_PREDATOR_INDEX]).getPersonnalite() != (Personnalite) MECHANT)
				{
					cerr << "Warning, animal with index " << REPETITIVE_PREDATOR_INDEX << " in menagerie is not a predator" << endl;
				}
				else
				{
					cout << "Pacman in predator test " << REPETITIVE_PREDATOR_INDEX << " with animal " << menagerie[REPETITIVE_PREDATOR_INDEX].getNomFR() << endl;
					animalIndex=REPETITIVE_PREDATOR_INDEX;
				}
			}
					#endif
				#else
					#ifdef _ORDERED_TEST_MODE
			animalIndex=getEvalIndex()%menagerie.getTaille();
					#else
						#ifdef _RANDOM_TEST_MODE
			double random = randomProb();

			if (random < 0.5)
			{

				animalIndex=randomInt(menagerie.getTaille());

				while (menagerie[animalIndex].getPersonnalite() =! (Personnalite)GENTIL)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}

				cout << "Pacman in prey test " << getTestIndex() << " with zoo " << animalIndex << endl;
			}
			else if (0.5 <=random)
			{
				animalIndex=randomInt(menagerie.getTaille());

				while (menagerie[animalIndex].getPersonnalite() =! (Personnalite)MECHANT)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}

				cout << "Pacman in predator test " << getEvalIndex() << " with zoo " << animalIndex << endl;

			}
						#else
							#ifdef _ALTERNATED_TEST_MODE
			if (getEvalIndex()%2==0)
			{
				animalIndex=randomInt(menagerie.getTaille());
	
				while (menagerie[animalIndex].getPersonnalite() != (Personnalite)GENTIL)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}
	
				cout << "Pacman in prey test " << getEvalIndex() << " with zoo " << animalIndex << endl;
	
			}
			else
			{
				animalIndex=randomInt(menagerie.getTaille());
	
				while (menagerie[animalIndex].getPersonnalite() != (Personnalite)MECHANT)
				{
					animalIndex=randomInt(menagerie.getTaille());
				}
	
				cout << "Pacman in predator test " << getEvalIndex() << " with zoo " << animalIndex << endl;
	
			}
							#else
			animalIndex=randomInt(menagerie.getTaille());
			cout << "Pacman entering test " << getEvalIndex() << " with zoo " << animalIndex << endl;
							#endif
						#endif
					#endif
				#endif	
	
			initComptMove();
			
				
				#ifdef _NO_MOVE_TEST_MODE
			testBestPacman(animalIndex);
				#else
			testPacman();
				#endif
			
				#ifdef _PHASE_TEST_MODE
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << ") to *** EDNetwork ***" << endl;
			//#endif
			sendVoidSynchro();
				#endif
			
			waitSynchro();
			
				#ifdef _PHASE_TEST_MODE
			if (getEvalIndex() < 2*NB_TESTED_ANIMALS+1)
			{
				//#ifdef _MPI_TEST
				cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << ") to *** EDNetwork ***" << endl;
				//#endif
				sendVoidSynchro();
			}
				#endif
		}
			#endif
		
			#ifdef _PHASE_TEST_MODE
		
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << "- - after wait synchro 2 - out of eval loop) to *** EDNetwork ***" << endl;
		//#endif
		sendVoidSynchro();
			#endif
		
		// On laisse tourner le réseau à vide
		waitSynchro();
		 
		incrementTestIndex();	
		
		if (getTestIndex() < NB_MULTI_TESTS+1)
		{
			
			#ifdef _ALL_TO_ALL_PROJECTION_MODE
				#ifdef _INHIB_RATIO_TEST_MODE
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending chromo to *** EDNetwork ***" << endl;
			//#endif
			sendSynchro();
				#else
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending skip synchro to *** EDNetwork ***" << endl;
			//#endif
			sendSkipSynchro();
				#endif
			#endif
			#ifdef _FIXED_RATIO_PROJECTION_MODE
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending chromo to *** EDNetwork ***" << endl;
			//#endif
			sendSynchro();
			#endif
		}
	}
		#else
		
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** integrating BirthFlash" << endl;
	//#endif
	integrateBirthFlash();

	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << ") to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
	
	// Attente initiale
	waitSynchro();
	
			#ifdef _PHASE_TEST_MODE
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << ") to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
			#endif
		
	//while (getEvalIndex() < 2*NB_TESTED_ANIMALS+1 && testSynchro())
	while (getEvalIndex() < 2*NB_TESTED_ANIMALS+1)
	{
		
		int animalIndex;
		 
			#ifdef _REPETITIVE_TEST_MODE	
				#ifdef _REPETITIVE_PREY_TEST_MODE 
			if (((Animal) menagerie[REPETITIVE_PREY_INDEX]).getPersonnalite() != (Personnalite) GENTIL)
			{
				cerr << "Warning, animal with index " << REPETITIVE_PREY_INDEX << " in menagerie is not a prey" << endl;
			}
			else
			{
				cout << "Pacman in prey test " << REPETITIVE_PREY_INDEX << " with animal " << menagerie[REPETITIVE_PREY_INDEX].getNomFR() << endl;
				animalIndex=REPETITIVE_PREY_INDEX;
			}
				#else
					#ifdef _REPETITIVE_PREDATOR_TEST_MODE 
			if (((Animal) menagerie[REPETITIVE_PREDATOR_INDEX]).getPersonnalite() != (Personnalite) MECHANT)
			{
				cerr << "Warning, animal with index " << REPETITIVE_PREDATOR_INDEX << " in menagerie is not a predator" << endl;
			}
			else
			{
				cout << "Pacman in predator test " << REPETITIVE_PREDATOR_INDEX << " with animal " << menagerie[REPETITIVE_PREDATOR_INDEX].getNomFR() << endl;
				animalIndex=REPETITIVE_PREDATOR_INDEX;
			}	
					#else
						#ifdef _ALTERNATED_REPETITIVE_TEST_MODE	
			if (getEvalIndex()%4 == 3)
			{
				if (((Animal) menagerie[REPETITIVE_PREY_INDEX]).getPersonnalite() != (Personnalite) GENTIL)
				{
					cerr << "Warning, animal with index " << REPETITIVE_PREY_INDEX << " in menagerie is not a prey" << endl;
				}
				else
				{
					cout << "Pacman in prey test " << REPETITIVE_PREY_INDEX << " with animal " << menagerie[REPETITIVE_PREY_INDEX].getNomFR() << endl;
					animalIndex=REPETITIVE_PREY_INDEX;
				}
			}
			else if (getEvalIndex()%4 == 1)
			{
				if (((Animal) menagerie[REPETITIVE_PREDATOR_INDEX]).getPersonnalite() != (Personnalite) MECHANT)
				{
					cerr << "Warning, animal with index " << REPETITIVE_PREDATOR_INDEX << " in menagerie is not a predator" << endl;
				}
				else
				{
					cout << "Pacman in predator test " << REPETITIVE_PREDATOR_INDEX << " with animal " << menagerie[REPETITIVE_PREDATOR_INDEX].getNomFR() << endl;
					animalIndex=REPETITIVE_PREDATOR_INDEX;
				}
			}
						#endif
					#endif
				#endif
			#else
				#ifdef _ORDERED_TEST_MODE
		animalIndex=getEvalIndex()%menagerie.getTaille();
				#else
					#ifdef _RANDOM_TEST_MODE
		double random = randomProb();

		if (random < 0.5)
		{
			animalIndex=randomInt(menagerie.getTaille());

			while (menagerie[animalIndex].getPersonnalite() != (Personnalite)GENTIL)
			{
				animalIndex=randomInt(menagerie.getTaille());
			}

			cout << "Pacman in prey test " << getTestIndex() << " with zoo " << animalIndex << endl;
		}
		else if (0.5 <=random)
		{
			animalIndex=randomInt(menagerie.getTaille());

			while (menagerie[animalIndex].getPersonnalite() != (Personnalite)MECHANT)
			{
				animalIndex=randomInt(menagerie.getTaille());
			}

			cout << "Pacman in predator test " << getEvalIndex() << " with zoo " << animalIndex << endl;

		}

					#else
						#ifdef _ALTERNATED_TEST_MODE
		if (getEvalIndex()%2==0)
		{
			animalIndex=randomInt(menagerie.getTaille());

			while (menagerie[animalIndex].getPersonnalite() != (Personnalite)GENTIL)
			{
				animalIndex=randomInt(menagerie.getTaille());
			}

			cout << "Pacman in prey test " << getEvalIndex() << " with zoo " << animalIndex << endl;

		}
		else
		{
			animalIndex=randomInt(menagerie.getTaille());

			while (menagerie[animalIndex].getPersonnalite() != (Personnalite)MECHANT)
			{
				animalIndex=randomInt(menagerie.getTaille());
			}

			cout << "Pacman in predator test " << getEvalIndex() << " with zoo " << animalIndex << endl;

		}
						#else
		animalIndex=randomInt(menagerie.getTaille());
		cout << "Pacman entering test " << getEvalIndex() << " with zoo " << animalIndex << endl;
						#endif
					#endif
				#endif
			#endif

		initComptMove();
		
			
		// Injection input
			#ifdef _NO_MOVE_TEST_MODE
		testBestPacman(animalIndex);
			#else
		testPacman();
			#endif
		
			#ifdef _PHASE_TEST_MODE
		sendVoidSynchro();
			#endif
		
		// Attente apres input	
		waitSynchro();

			#ifdef _PHASE_TEST_MODE
		if (getEvalIndex() < 2*NB_TESTED_ANIMALS+1)
		{
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << ") to *** EDNetwork ***" << endl;
			//#endif
			sendVoidSynchro();
		}
			#endif
	}
	
			#ifdef _PHASE_TEST_MODE
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << " - out of eval loop) to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
			#endif
	
	// On laisse tourner le réseau à vide à la fin de la simulation
	waitSynchro();
	//incrementEvalIndex();
	
		#endif
}
	#endif

		#ifdef _NO_MOVE_TEST_MODE
void Pacman::integrateTestOutputs(const Animal& animalTest)
{

			#ifdef _GRAPHICAL_DISPLAY_MODE
	((PacmanDisplayer*) displayer)->cleanDisplay();
			#endif

	bool visioFlag=1;
	bool audioFlag=1;

	for (int i=0;i<nbOutputBuffers;i++)
	{
			#ifdef _MPI_TEST
		cout << "*** Pacman *** Output Buffer " << i << " " << outputBuffers[i]->getFlag() << endl;;
			#endif

		if (outputBuffers[i]->getFlag())
		{
			if (outputBuffers[i]->isActive())
			{
				if(FIRST_VISIO_CHANNEL_ETIQUETTE<=i && i<LAST_VISIO_CHANNEL_ETIQUETTE)
				{
					visioFlag = 0;
				}
				else if(i==LEFT_AUDIO_CHANNEL_ETIQUETTE || i==RIGHT_AUDIO_CHANNEL_ETIQUETTE)
				{
					audioFlag = 0;
				}
			}
		}
	}

			#ifdef _BIMODAL_TEST_MODE
	if (visioFlag)
	{
		Image* imageVue=static_cast<Image*>(animalTest.getModalite(0)->clone());

		outputBuffers[TEST_VISIO_INPUT_ASSEMBLY]->integrateOutput(*imageVue);

				#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->setObjetAVoir(imageVue,0,0,2);
				#endif

		delete(imageVue);
	}

	if (audioFlag)
	{
			// Son à gauche

		// Calcul du son entendu par l'oreille gauche
		Son* sonEntenduLeft=static_cast<Son*>(animalTest.getModalite(1)->clone());

		// Envoi du son
				#ifdef _MPI_TEST
		cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
				#endif
		outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);

				#ifdef _GRAPHICAL_DISPLAY_MODE
		// Affichage du son
		((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,0,0,0);
				#endif
		delete(sonEntenduLeft);


			// Son à droite
			
		// Calcul du son entendu par l'oreille droite
		Son* sonEntenduRight=static_cast<Son*>(animalTest.getModalite(1)->clone());
		
		// Envoi du son
				#ifdef _MPI_TEST
		cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
				#endif
				
		outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
				#ifdef _GRAPHICAL_DISPLAY_MODE
		// Affichage du son
		((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduRight,0,0,1);
				#endif
		delete(sonEntenduRight);
	}
 			#else
				#ifdef _VISIO_TEST_MODE
	if (visioFlag)
	{
		Image* imageVue=static_cast<Image*>(animalTest.getModalite(0)->clone());

		outputBuffers[TEST_VISIO_INPUT_ASSEMBLY]->integrateOutput(*imageVue);

				#ifdef _GRAPHICAL_DISPLAY_MODE
		((PacmanDisplayer*) displayer)->setObjetAVoir(imageVue,0,0,2);
				#endif
				
		delete(imageVue);
	}
				#else
					#ifdef _AUDIO_TEST_MODE
	if (audioFlag)
	{
			// Son à gauche
			
		// Calcul du son entendu par l'oreille gauche
		Son* sonEntenduLeft=static_cast<Son*>(animalTest.getModalite(1)->clone());
		
		// Envoi du son
				#ifdef _MPI_TEST
		cout << "*** Pacman *** sending left hear sound to ***BAM***" << endl;
				#endif
		outputBuffers[LEFT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduLeft);
				
				#ifdef _GRAPHICAL_DISPLAY_MODE
		// Affichage du son
		((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,0,0,0);
				#endif
		delete(sonEntenduLeft);


			// Son à droite
			
		// Calcul du son entendu par l'oreille droite
		Son* sonEntenduRight=static_cast<Son*>(animalTest.getModalite(1)->clone());
		
		// Envoi du son
#ifdef _MPI_TEST
		cout << "*** Pacman *** sending right hear sound to ***BAM***" << endl;
#endif
		outputBuffers[RIGHT_AUDIO_CHANNEL_ETIQUETTE]->integrateOutput(*sonEntenduRight);
				#ifdef _GRAPHICAL_DISPLAY_MODE
		// Affichage du son
		((PacmanDisplayer*) displayer)->setObjetAEntendre(sonEntenduLeft,0,0,1);
				#endif
		delete(sonEntenduRight);
	}
					#endif
				#endif
			#endif
	
			#ifdef _GRAPHICAL_DISPLAY_MODE
	((PacmanDisplayer*) displayer)->flushDisplay();
			#endif

}
	
void Pacman::testBestPacman(int animalIndex)
{
	cout << "*** Pacman *** entering test loop for individual " << getTopoIndex() << endl;

			#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t1;
	time (&t1);
			#endif
			
			#ifdef _TRANSITION_STAT_MODE
	int waitNbSteps = 0;
	
	while(waitNbSteps<EDNetwork::TRANSITION_TIME_LENGTH && testSynchro())
	{
				#ifdef _MPI_TEST
		cerr << "*** Pacman *** test best loop for individual " << getTopoIndex() << " at step " << nbTestSteps << endl;
				#endif
			
		integrateTestOutputs(menagerie[animalIndex]);

		sendOutputs();

		waitNbSteps++;
	}
	
	incrementEvalIndex();
				#ifdef _PHASE_TEST_MODE
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro (" << getEvalIndex() << " - in testBest) to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
				#endif
		
	while(waitNbSteps<NB_MAX_TEST_STEPS && testSynchro())
	{
				#ifdef _MPI_TEST
		cerr << "*** Pacman *** test best loop for individual " << getTopoIndex() << " at step " << nbTestSteps << endl;
				#endif
			
		integrateTestOutputs(menagerie[animalIndex]);

		sendOutputs();

		waitNbSteps++;
	}
	
	incrementEvalIndex();
		
			#else
	
	int waitNbSteps = 0;

	while(waitNbSteps<NB_MAX_TEST_STEPS && testSynchro())
	{
				#ifdef _MPI_TEST
		cerr << "*** Pacman *** test best loop for individual " << getTopoIndex() << " at step " << nbTestSteps << endl;
				#endif
			
		integrateTestOutputs(menagerie[animalIndex]);

		sendOutputs();

		waitNbSteps++;
	}
	
	incrementEvalIndex();
		
			#endif

			#ifdef _REAL_TIME_OF_COMPUTING_MODE
	time_t t2;
	time(&t2);
			#endif

	cout << "*** Pacman *** out of test " << getTestIndex() <<  " loop for individual " << getTopoIndex() << " after " << waitNbSteps << " steps (" << difftime(t2,t1) << ")" << endl;

}
		#endif
	//#endif
#else
	//#ifdef _TEST_BEST_POPULATION_MODE
void Pacman::testVoid()
{
	
	initComptMove();
	
		#ifdef _MULTI_TEST_MODE
	initTestIndex();

	while (getTestIndex() < NB_MULTI_TESTS+1)
	{
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** integrating BirthFlash" << endl;
		//#endif
		integrateBirthFlash();
	
		//#ifdef _PHASE_TEST_MODE
		//#ifdef _MPI_TEST
		cout << "*** Pacman *** sending void synchro to *** EDNetwork ***" << endl;
		//#endif
		sendVoidSynchro();
		//testSynchro();
		
		//#endif
		waitSynchro();
		//testSynchro();
		
		incrementTestIndex();

		if (getTestIndex() < NB_MULTI_TESTS+1)
		{
			//#ifdef _MPI_TEST
			cout << "*** Pacman *** sending skip synchro to *** EDNetwork ***" << endl;
			//#endif
			sendSkipSynchro();
		}
		
	}
		#else
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** integrating BirthFlash" << endl;
	//#endif
	integrateBirthFlash();

	//#ifdef _PHASE_TEST_MODE
	//#ifdef _MPI_TEST
	cout << "*** Pacman *** sending void synchro to *** EDNetwork ***" << endl;
	//#endif
	sendVoidSynchro();
	//testSynchro();
	
	//#endif
	waitSynchro();
	//testSynchro();
		#endif
}	
	//#endif
#endif

ostream& operator<<(ostream& o, Pacman* p)
{
	o << (Chromosome*) p;

	return o;
}

istream& operator>>(istream& i, Pacman* p)
{
	if(i >> (Chromosome*) p)
	{
		cout << "Reading chromosome ok" << endl;
	}
	else
	{
		cerr << "Warning, unable to read chromosome" << endl;
	}
	
	return i;
}
