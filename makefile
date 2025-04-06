############################################################ Flags de compilation ###########################################################
DEBUGGER=0
ifeq ($(DEBUGGER),1)
	GCC = g++ -g -c
else
	GCC = g++ -c -lX11
endif

LD = g++  -lX11

MPICC = mpic++ -lm -L/usr/X11R6/lib -lX11 -lXpm
MPIRUN = mpirun -f -c

############################################################ Répertoires sources ###########################################################

## Repertoire Algo genetique
GA = GeneticAlgorithm/

## Repertoires Pacman
MPI = mpi/
FEN = Fenetre/
OBJ = Objets/
ZOO = Zoo/
FH = Files/
HAN = Handlers/
INT = Interfaces/
WIN = Windows/
STA = Staters/
TRA = Tracers/
GRA = Graphers/
SAV = Savers/
LOA = Loaders/
TES = Testers/

## Repertoires pEDBAM
DGR = DirectedGraph/
TOPO = Topology/
EDMAN = EventManager/
PHY = Physiology/
MT = MathTools/
EDNN = EDNetwork/

############################################################################################################################################
compilEDPacman: RunEvoPacman

statEvo: StatEvoPacman
	$(MPIRUN) 2 StatEvoPacman

runEvo: RunEvoPacman
	$(MPIRUN) 2 RunEvoPacman

testEvo: TestEvoPacman
	$(MPIRUN) 2 TestEvoPacman

testBest: TestBestPopulation
	$(MPIRUN) 2 TestBestPopulation

StatEvoPacman: O_OBJ O_INT O_HAN O_FH O_FEN O_DGR O_MT O_TOPO O_PHY O_EDMAN O_MPI O_EDNN O_GA O_ZOO O_GRA O_TRA O_STA O_SAV O_LOA O_WIN O_TES stat.o
	$(MPICC) stat.o TestLab.o Savable.o Loadable.o Statable.o Displayable.o Tracable.o EvoIndexable.o EvalIndexable.o  TestIndexable.o Testable.o TopoIndexable.o Graphable.o SynchroModule.o RootModule.o MPIModule.o Link.o Node.o InputAssembly.o OutputAssembly.o OutputBuffer.o InputBuffer.o GenericBuffer.o MpiGlobals.o ImagePixmap.o Fenetre.o EnvGraph.o Palette.o IndexedObject.o AccuDataFile.o FileObject.o LinkedObject.o Object.o Zoo.o Pacman.o Menagerie.o Animal.o Son.o Image.o ObjetSensitif.o OngoingDistributionGnuplotFile.o DistributionGnuplotFile.o GnuplotFile.o DistributionDataFile.o OngoingDistributionDataFile.o DataFile.o IOFile.o Tester.o Stater.o Displayer.o Tracer.o Accumulater.o Counter.o MeanLogDistribution.o MeanDistribution.o Distribution.o LogDistribution.o CumulatedDistribution.o OngoingMeanDistribution.o OngoingDistribution.o OngoingCumulatedDistribution.o OngoingMeanLogDistribution.o Loader.o Saver.o Grapher.o Handler.o ZooDisplayer.o PacmanDisplayer.o TopologyDisplayer.o AssemblyDisplayer.o NeuronDisplayer.o ActivityStater.o InputStater.o NeuronStater.o InhibSynapseStater.o ExcitSynapseStater.o SynapseStater.o ZooStater.o LoopStater.o AssemblyStater.o ClusterStater.o LinkedClusterStater.o NetworkStater.o ActivityTester.o InputTester.o ZooSaver.o ZooLoader.o InputAssemblyStater.o OutputAssemblyStater.o IndividualTracer.o ZooTracer.o SynapseTracer.o NeuronTracer.o AssemblyTracer.o NetworkTracer.o ZooGrapher.o IndividualGrapher.o NetworkGrapher.o AssemblyGrapher.o NeuronGrapher.o SynapseGrapher.o Topology.o LinkedCluster.o ClusterLink.o Cluster.o Projection.o Assembly.o Neuron.o Synapse.o EventManager.o CircledList.o PspEventPackage.o List.o PreConstructedList.o SpikingNeuron.o DynamicSynapse.o NeuronMathTools.o SynapseMathTools.o RandomMathTools.o RandomNumberGenerator.o EDNetwork.o EDExcitProjection.o EDInhibProjection.o EDAssembly.o EDNeuron.o EDInhibSynapse.o EDExcitSynapse.o EDSynapse.o EvoNetwork.o Population.o Individual.o Chromosome.o Gene.o -o StatEvoPacman


RunEvoPacman: O_OBJ O_INT O_HAN O_FH O_FEN O_DGR O_MT O_TOPO O_PHY O_EDMAN O_MPI O_EDNN O_GA O_ZOO O_GRA O_TRA O_STA O_SAV O_LOA O_WIN O_TES run.o
	$(MPICC) run.o TestLab.o Savable.o Loadable.o Statable.o Displayable.o Tracable.o EvoIndexable.o EvalIndexable.o  TestIndexable.o Testable.o TopoIndexable.o Graphable.o SynchroModule.o RootModule.o MPIModule.o Link.o Node.o InputAssembly.o OutputAssembly.o OutputBuffer.o InputBuffer.o GenericBuffer.o MpiGlobals.o ImagePixmap.o Fenetre.o EnvGraph.o Palette.o IndexedObject.o AccuDataFile.o FileObject.o LinkedObject.o Object.o Zoo.o Pacman.o Menagerie.o Animal.o Son.o Image.o ObjetSensitif.o OngoingDistributionGnuplotFile.o DistributionGnuplotFile.o GnuplotFile.o DistributionDataFile.o OngoingDistributionDataFile.o DataFile.o IOFile.o Tester.o Stater.o Displayer.o Tracer.o Accumulater.o Counter.o MeanLogDistribution.o MeanDistribution.o Distribution.o LogDistribution.o CumulatedDistribution.o OngoingDistribution.o OngoingMeanDistribution.o OngoingCumulatedDistribution.o OngoingMeanLogDistribution.o Loader.o Saver.o Grapher.o Handler.o ZooDisplayer.o PacmanDisplayer.o TopologyDisplayer.o AssemblyDisplayer.o NeuronDisplayer.o ActivityStater.o InputStater.o NeuronStater.o InhibSynapseStater.o ExcitSynapseStater.o SynapseStater.o ZooStater.o LoopStater.o AssemblyStater.o ClusterStater.o LinkedClusterStater.o NetworkStater.o ActivityTester.o InputTester.o ZooSaver.o ZooLoader.o InputAssemblyStater.o OutputAssemblyStater.o IndividualTracer.o ZooTracer.o SynapseTracer.o NeuronTracer.o AssemblyTracer.o NetworkTracer.o ZooGrapher.o IndividualGrapher.o NetworkGrapher.o AssemblyGrapher.o NeuronGrapher.o SynapseGrapher.o Topology.o LinkedCluster.o ClusterLink.o Cluster.o Projection.o Assembly.o Neuron.o Synapse.o EventManager.o CircledList.o PspEventPackage.o List.o PreConstructedList.o SpikingNeuron.o DynamicSynapse.o NeuronMathTools.o SynapseMathTools.o RandomMathTools.o RandomNumberGenerator.o EDNetwork.o EDExcitProjection.o EDInhibProjection.o EDAssembly.o EDNeuron.o EDInhibSynapse.o EDExcitSynapse.o EDSynapse.o EvoNetwork.o Population.o Individual.o Chromosome.o Gene.o -o RunEvoPacman

TestEvoPacman: O_OBJ O_INT O_HAN O_FH O_FEN O_DGR O_MT O_TOPO O_PHY O_EDMAN O_MPI O_EDNN O_GA O_ZOO O_GRA O_TRA O_STA O_SAV O_LOA O_WIN O_TES test.o
	$(MPICC) test.o TestLab.o Link.o Node.o SynchroModule.o RootModule.o MPIModule.o InputAssembly.o OutputAssembly.o OutputBuffer.o InputBuffer.o GenericBuffer.o MpiGlobals.o ImagePixmap.o Fenetre.o EnvGraph.o Palette.o IndexedObject.o FileObject.o LinkedObject.o Object.o Zoo.o Pacman.o Menagerie.o Animal.o Son.o Image.o ObjetSensitif.o OngoingDistributionGnuplotFile.o DistributionGnuplotFile.o GnuplotFile.o DistributionDataFile.o OngoingDistributionDataFile.o AccuDataFile.o DataFile.o IOFile.o Counter.o Accumulater.o MeanLogDistribution.o MeanDistribution.o Distribution.o LogDistribution.o CumulatedDistribution.o OngoingDistribution.o OngoingMeanDistribution.o OngoingCumulatedDistribution.o OngoingMeanLogDistribution.o Stater.o Tester.o Displayer.o Tracer.o Loader.o Saver.o Grapher.o Handler.o Loadable.o Savable.o Statable.o Displayable.o Tracable.o EvoIndexable.o EvalIndexable.o TopoIndexable.o TestIndexable.o Testable.o Graphable.o ZooDisplayer.o PacmanDisplayer.o TopologyDisplayer.o AssemblyDisplayer.o NeuronDisplayer.o ActivityStater.o InputStater.o NeuronStater.o InhibSynapseStater.o ExcitSynapseStater.o SynapseStater.o ZooStater.o LoopStater.o AssemblyStater.o ClusterStater.o LinkedClusterStater.o  NetworkStater.o ActivityTester.o InputTester.o ZooSaver.o ZooLoader.o InputAssemblyStater.o OutputAssemblyStater.o IndividualTracer.o ZooTracer.o SynapseTracer.o NeuronTracer.o AssemblyTracer.o NetworkTracer.o ZooGrapher.o IndividualGrapher.o NetworkGrapher.o AssemblyGrapher.o NeuronGrapher.o SynapseGrapher.o Topology.o LinkedCluster.o ClusterLink.o Cluster.o Projection.o Assembly.o Neuron.o Synapse.o EventManager.o CircledList.o PspEventPackage.o List.o PreConstructedList.o SpikingNeuron.o DynamicSynapse.o NeuronMathTools.o SynapseMathTools.o RandomMathTools.o RandomNumberGenerator.o EDNetwork.o EDExcitProjection.o EDInhibProjection.o EDAssembly.o EDNeuron.o EDInhibSynapse.o EDExcitSynapse.o EDSynapse.o EvoNetwork.o Population.o Individual.o Chromosome.o Gene.o -o TestEvoPacman

TestBestPopulation: O_OBJ O_INT O_HAN O_FH O_FEN O_DGR O_MT O_TOPO O_PHY O_EDMAN O_MPI O_EDNN O_GA O_ZOO O_GRA O_TRA O_STA O_SAV O_LOA O_WIN O_TES testBest.o
	$(MPICC) testBest.o TestLab.o Link.o Node.o SynchroModule.o RootModule.o MPIModule.o InputAssembly.o OutputAssembly.o OutputBuffer.o InputBuffer.o GenericBuffer.o MpiGlobals.o ImagePixmap.o Fenetre.o EnvGraph.o Palette.o IndexedObject.o FileObject.o LinkedObject.o Object.o Zoo.o Pacman.o Menagerie.o Animal.o Son.o Image.o ObjetSensitif.o OngoingDistributionGnuplotFile.o DistributionGnuplotFile.o GnuplotFile.o DistributionDataFile.o OngoingDistributionDataFile.o AccuDataFile.o DataFile.o IOFile.o Counter.o Accumulater.o MeanLogDistribution.o MeanDistribution.o Distribution.o LogDistribution.o CumulatedDistribution.o OngoingDistribution.o OngoingMeanDistribution.o OngoingCumulatedDistribution.o OngoingMeanLogDistribution.o Stater.o Tester.o Displayer.o Tracer.o Loader.o Saver.o Grapher.o Handler.o Loadable.o Savable.o Statable.o Displayable.o Tracable.o EvoIndexable.o EvalIndexable.o TopoIndexable.o TestIndexable.o Testable.o Graphable.o ZooDisplayer.o PacmanDisplayer.o TopologyDisplayer.o AssemblyDisplayer.o NeuronDisplayer.o ActivityStater.o InputStater.o NeuronStater.o InhibSynapseStater.o ExcitSynapseStater.o SynapseStater.o ZooStater.o LoopStater.o AssemblyStater.o ClusterStater.o LinkedClusterStater.o NetworkStater.o ActivityTester.o InputTester.o ZooSaver.o ZooLoader.o InputAssemblyStater.o OutputAssemblyStater.o IndividualTracer.o ZooTracer.o SynapseTracer.o NeuronTracer.o AssemblyTracer.o NetworkTracer.o ZooGrapher.o IndividualGrapher.o NetworkGrapher.o AssemblyGrapher.o NeuronGrapher.o SynapseGrapher.o Topology.o LinkedCluster.o ClusterLink.o Cluster.o Projection.o Assembly.o Neuron.o Synapse.o EventManager.o CircledList.o PspEventPackage.o List.o PreConstructedList.o SpikingNeuron.o DynamicSynapse.o NeuronMathTools.o SynapseMathTools.o RandomMathTools.o RandomNumberGenerator.o EDNetwork.o EDExcitProjection.o EDInhibProjection.o EDAssembly.o EDNeuron.o EDInhibSynapse.o EDExcitSynapse.o EDSynapse.o EvoNetwork.o Population.o Individual.o Chromosome.o Gene.o -o TestBestPopulation

cleanAll: clean cleanTmp cleanData cleanChromo

clean:
	rm -f *.o

cleanTmp:
	rm -rf *~
	rm -rf */*~

cleanData:
	rm -f data/*.dat data/*.eps data/*.gnu

cleanChromo:
	rm -f data/Chromo*.txt

############################################################ Repertoires des objets ###########################################################

## Repertoire Algo genetique
O_GA :  Gene.o Chromosome.o Population.o Individual.o EvoNetwork.o

## Repertoires Pacman
O_MPI : MpiGlobals.o GenericBuffer.o OutputBuffer.o InputBuffer.o InputAssembly.o OutputAssembly.o MPIModule.o SynchroModule.o RootModule.o
O_FEN : ImagePixmap.o EnvGraph.o Palette.o Fenetre.o
O_OBJ : Object.o IndexedObject.o FileObject.o LinkedObject.o
O_ZOO : ObjetSensitif.o Son.o Image.o Animal.o Menagerie.o Pacman.o Zoo.o
O_FH : IOFile.o DataFile.o AccuDataFile.o DistributionDataFile.o OngoingDistributionDataFile.o GnuplotFile.o DistributionGnuplotFile.o OngoingDistributionGnuplotFile.o
#O_HAN : Displayer.o Tracer.o EvoGrapher.o Grapher.o Stater.o Saver.o Loader.o Counter.o Accumulater.o
O_HAN : Handler.o Grapher.o Tracer.o Stater.o Saver.o Loader.o Counter.o Distribution.o LogDistribution.o Accumulater.o MeanDistribution.o CumulatedDistribution.o MeanLogDistribution.o OngoingDistribution.o OngoingMeanDistribution.o OngoingCumulatedDistribution.o OngoingMeanLogDistribution.o Displayer.o Tester.o
O_INT : Displayable.o Tracable.o EvalIndexable.o EvoIndexable.o TopoIndexable.o TestIndexable.o Testable.o Graphable.o Statable.o Savable.o Loadable.o
O_WIN : ZooDisplayer.o PacmanDisplayer.o TopologyDisplayer.o AssemblyDisplayer.o NeuronDisplayer.o
O_STA : SynapseStater.o InhibSynapseStater.o ExcitSynapseStater.o NeuronStater.o InputStater.o ActivityStater.o LoopStater.o AssemblyStater.o InputAssemblyStater.o OutputAssemblyStater.o ClusterStater.o LinkedClusterStater.o NetworkStater.o ZooStater.o
O_TRA : SynapseTracer.o NeuronTracer.o AssemblyTracer.o NetworkTracer.o ZooTracer.o IndividualTracer.o DefineTracer.h
O_GRA : SynapseGrapher.o  NeuronGrapher.o AssemblyGrapher.o NetworkGrapher.o IndividualGrapher.o ZooGrapher.o
O_SAV : ZooSaver.o
O_LOA : ZooLoader.o
#O_TES : TestLab.o
O_TES : TestLab.o ActivityTester.o InputTester.o

## Repertoires pEDBAM
O_DGR : Node.o Link.o
O_TOPO : Synapse.o Neuron.o  Assembly.o Projection.o Cluster.o ClusterLink.o LinkedCluster.o Topology.o
O_EDMAN : PspEventPackage.o List.o PreConstructedList.o CircledList.o EventManager.o
O_PHY : SpikingNeuron.o DynamicSynapse.o
O_MT : NeuronMathTools.o SynapseMathTools.o RandomMathTools.o RandomNumberGenerator.o
O_EDNN : EDSynapse.o EDInhibSynapse.o EDExcitSynapse.o EDNeuron.o EDExcitProjection.o EDInhibProjection.o EDAssembly.o EDNetwork.o

############################################################# main #########################################################################

testBest.o : Define.h DefineMPI.h DefineEDNetwork.h $(MPI)MpiGlobals.h $(GA)EvoNetwork.h $(ZOO)TestLab.h testBest.cc
	$(GCC) testBest.cc

test.o : Define.h DefineMPI.h DefineEDNetwork.h $(MPI)MpiGlobals.h $(GA)EvoNetwork.h $(ZOO)TestLab.h test.cc
	$(GCC) test.cc

run.o : Define.h DefineMPI.h DefineEDNetwork.h $(MPI)MpiGlobals.h $(GA)EvoNetwork.h $(ZOO)Zoo.h run.cc
	$(GCC) run.cc

stat.o : Define.h DefineMPI.h DefineEDNetwork.h $(MPI)MpiGlobals.h $(GA)EvoNetwork.h $(ZOO)Zoo.h stat.cc
	$(GCC) stat.cc

############################################################################################################################################
########################################################### Pacman #########################################################################
############################################################################################################################################

########################################################## GeneticAlgorithm #################################################################

EvoNetwork.o: $(GA)EvoNetwork.cc $(GA)EvoNetwork.h $(EDNN)EDNetwork.h $(TES)ActivityTester.h $(TES)InputTester.h $(INT)EvoIndexable.h $(INT)EvalIndexable.h $(INT)Testable.h DefineStater.h DefineTracer.h DefineWindow.h DefineEDNetwork.h DefineMPI.h DefineZoo.h DefineGA.h Define.h
	$(GCC) $(GA)EvoNetwork.cc

Population.o: $(GA)Population.cc $(GA)Population.h $(GA)Chromosome.h $(GA)Gene.h $(INT)EvoIndexable.h $(INT)TopoIndexable.h $(OBJ)IndexedObject.h $(MT)RandomMathTools.h DefineGA.h Define.h
	$(GCC) $(GA)Population.cc

Individual.o: $(GA)Individual.h $(GA)Individual.cc $(HAN)Accumulater.h $(INT)EvalIndexable.h $(INT)Graphable.h $(INT)Tracable.h $(TRA)IndividualTracer.h $(GRA)IndividualGrapher.h DefineZoo.h DefineGA.h Define.h DefineTracer.h DefineGrapher.h
	$(GCC) $(GA)Individual.cc

Chromosome.o: $(GA)Chromosome.cc $(GA)Chromosome.h $(GA)Gene.h $(OBJ)Object.h $(INT)Savable.h $(INT)EvoIndexable.h $(INT)TopoIndexable.h $(MT)RandomMathTools.h DefineGA.h Define.h
	$(GCC) $(GA)Chromosome.cc

Gene.o: $(GA)Gene.cc $(GA)Gene.h $(OBJ)IndexedObject.h $(MT)RandomMathTools.h DefineGA.h Define.h
	$(GCC) $(GA)Gene.cc

############################################################# Zoo ##########################################################################
# Ancien pacman2_zoo2

TestLab.o : $(ZOO)TestLab.cc $(ZOO)TestLab.h $(ZOO)Zoo.h $(ZOO)Pacman.h $(ZOO)Menagerie.h DefineTester.h DefineStater.h DefineTracer.h DefineGrapher.h DefineGA.h DefineZoo.h Define.h
	$(GCC) $(ZOO)TestLab.cc

Zoo.o : $(ZOO)Zoo.cc $(ZOO)Zoo.h $(ZOO)Pacman.h $(ZOO)Menagerie.h $(INT)Displayable.h $(INT)Loadable.h $(INT)Savable.h $(INT)Statable.h $(INT)Tracable.h $(INT)Graphable.h $(TRA)ZooTracer.h $(GRA)ZooGrapher.h $(SAV)ZooSaver.h $(LOA)ZooLoader.h $(STA)ZooStater.h $(OBJ)FileObject.h $(WIN)ZooDisplayer.h $(GA)Population.h $(ZOO)Menagerie.h $(MT)RandomNumberGenerator.h $(MT)RandomMathTools.h $(OBJ)FileObject.h DefineWindow.h DefineStater.h DefineTracer.h DefineGrapher.h DefineGA.h DefineZoo.h Define.h
	$(GCC) $(ZOO)Zoo.cc

Pacman.o : $(ZOO)Pacman.cc $(ZOO)Pacman.h $(ZOO)Zoo.h $(ZOO)Menagerie.h $(ZOO)Animal.h $(WIN)PacmanDisplayer.h $(MT)RandomMathTools.h $(GA)Individual.h $(EDNN)EDNetwork.h $(INT)TestIndexable.h $(INT)Displayable.h $(MPI)RootModule.h DefineWindow.h DefineTester.h DefineStater.h DefineZoo.h DefineMPI.h Define.h DefineEDNetwork.h DefineGA.h
	$(GCC) $(ZOO)Pacman.cc

Menagerie.o : $(ZOO)Menagerie.cc $(ZOO)Menagerie.h $(ZOO)Animal.h
	$(GCC) $(ZOO)Menagerie.cc

Animal.o: $(ZOO)Animal.cc $(ZOO)Animal.h $(ZOO)Son.h $(ZOO)Image.h $(ZOO)ObjetSensitif.h DefineZoo.h Define.h
	$(GCC) $(ZOO)Animal.cc

Son.o : $(ZOO)Son.cc $(ZOO)Son.h $(ZOO)ObjetSensitif.h
	$(GCC) $(ZOO)Son.cc

Image.o : $(ZOO)Image.cc $(ZOO)Image.h $(ZOO)ObjetSensitif.h
	$(GCC) $(ZOO)Image.cc

ObjetSensitif.o : $(ZOO)ObjetSensitif.cc $(ZOO)ObjetSensitif.h $(MT)RandomMathTools.h
	$(GCC) $(ZOO)ObjetSensitif.cc

############################################################ Windows #######################################################################

TopologyDisplayer.o : $(WIN)TopologyDisplayer.cc $(WIN)TopologyDisplayer.h $(WIN)AssemblyDisplayer.h  $(TOPO)Topology.h DefineStater.h DefineWindow.h DefineZoo.h DefineEDNetwork.h DefineGA.h Define.h
	$(GCC) $(WIN)TopologyDisplayer.cc

AssemblyDisplayer.o : $(WIN)AssemblyDisplayer.cc $(WIN)AssemblyDisplayer.h $(WIN)NeuronDisplayer.h $(TOPO)Assembly.h DefineStater.h DefineWindow.h DefineZoo.h DefineEDNetwork.h DefineGA.h Define.h
	$(GCC) $(WIN)AssemblyDisplayer.cc

NeuronDisplayer.o : $(WIN)NeuronDisplayer.cc $(WIN)NeuronDisplayer.h $(HAN)Displayer.h $(TOPO)Neuron.h $(FEN)Fenetre.h DefineStater.h DefineWindow.h DefineZoo.h DefineEDNetwork.h DefineGA.h Define.h
	$(GCC) $(WIN)NeuronDisplayer.cc

ZooDisplayer.o : $(WIN)ZooDisplayer.cc $(WIN)ZooDisplayer.h $(HAN)Displayer.h $(ZOO)Zoo.h DefineWindow.h DefineZoo.h Define.h
	$(GCC) $(WIN)ZooDisplayer.cc

PacmanDisplayer.o : $(WIN)PacmanDisplayer.cc $(WIN)PacmanDisplayer.h $(HAN)Displayer.h $(ZOO)Pacman.h $(ZOO)Animal.h $(ZOO)Son.h $(ZOO)Image.h DefineWindow.h DefineZoo.h Define.h
	$(GCC) $(WIN)PacmanDisplayer.cc

############################################################ Fenetre #######################################################################
# Ancien pacman2_fenetre

ImagePixmap.o: $(FEN)ImagePixmap.cc $(FEN)ImagePixmap.h $(FEN)Fenetre.h
	$(GCC) $(FEN)ImagePixmap.cc

Fenetre.o: $(FEN)Fenetre.cc $(FEN)Fenetre.h $(FEN)EnvGraph.h $(FEN)ImagePixmap.h
	$(GCC) $(FEN)Fenetre.cc

EnvGraph.o: $(FEN)EnvGraph.cc $(FEN)EnvGraph.h $(FEN)Palette.h
	$(GCC) $(FEN)EnvGraph.cc

Palette.o: $(FEN)Palette.cc $(FEN)Palette.h $(FEN)EnvGraph.h
	$(GCC) $(FEN)Palette.cc

################################################################ MPI #######################################################################
# Ancien pacman2_MPI

RootModule.o: $(MPI)RootModule.cc $(MPI)RootModule.h $(MPI)MPIModule.h DefineMPI.h DefineEDNetwork.h Define.h
	$(GCC) $(MPI)RootModule.cc

SynchroModule.o: $(MPI)SynchroModule.cc $(MPI)SynchroModule.h $(MPI)MPIModule.h DefineMPI.h DefineEDNetwork.h Define.h
	$(GCC) $(MPI)SynchroModule.cc

MPIModule.o: $(MPI)MPIModule.cc $(MPI)MPIModule.h $(MPI)InputBuffer.h $(MPI)OutputBuffer.h $(MPI)MpiGlobals.h DefineMPI.h Define.h
	$(GCC) $(MPI)MPIModule.cc

InputAssembly.o: $(MPI)InputAssembly.cc $(MPI)InputAssembly.h $(MPI)MpiGlobals.h $(MPI)InputBuffer.h $(EDNN)EDAssembly.h $(STA)InputAssemblyStater.h DefineStater.h DefineZoo.h DefinePhysiology.h DefineEDNetwork.h DefineMPI.h Define.h
	$(GCC) $(MPI)InputAssembly.cc

OutputAssembly.o: $(MPI)OutputAssembly.cc $(MPI)OutputAssembly.h $(MPI)MpiGlobals.h $(MPI)OutputBuffer.h $(EDNN)EDAssembly.h $(STA)OutputAssemblyStater.h DefineStater.h DefinePhysiology.h DefineEDNetwork.h DefineMPI.h Define.h
	$(GCC) $(MPI)OutputAssembly.cc

InputBuffer.o: $(MPI)InputBuffer.h $(MPI)InputBuffer.cc $(MPI)MpiGlobals.h $(MPI)Buffer.h Define.h
	$(GCC) $(MPI)InputBuffer.cc

OutputBuffer.o: $(MPI)OutputBuffer.h $(MPI)OutputBuffer.cc $(MPI)MpiGlobals.h $(MPI)Buffer.h Define.h
	$(GCC) $(MPI)OutputBuffer.cc

GenericBuffer.o: $(MPI)GenericBuffer.cc $(MPI)GenericBuffer.h DefineMPI.h Define.h
	$(GCC) $(MPI)GenericBuffer.cc

MpiGlobals.o: $(MPI)MpiGlobals.cc $(MPI)MpiGlobals.h DefineMPI.h Define.h
	$(MPICC) -nostartfiles $(MPI)MpiGlobals.cc

############################################################################################################################################
################################################### BAM Bimodale Evenementielle ############################################################
############################################################################################################################################

################################################################ Savers ####################################################################

ZooSaver.o : $(SAV)ZooSaver.cc $(SAV)ZooSaver.h $(ZOO)Zoo.h $(HAN)Saver.h $(FH)IOFile.h DefineGA.h DefineSaver.h Define.h
	$(GCC) $(SAV)ZooSaver.cc

################################################################ Loaders ####################################################################

ZooLoader.o : $(LOA)ZooLoader.cc $(LOA)ZooLoader.h $(ZOO)Zoo.h $(HAN)Loader.h $(FH)IOFile.h DefineGA.h DefineStater.h DefineSaver.h Define.h
	$(GCC) $(LOA)ZooLoader.cc


################################################################ Testers ####################################################################

InputTester.o : $(TES)InputTester.h $(TES)InputTester.cc $(GA)EvoNetwork.h $(STA)InputStater.h $(HAN)Tester.h DefineEDNetwork.h DefineGrapher.h DefineTracer.h DefineStater.h DefineTester.h DefineZoo.h Define.h
	$(GCC) $(TES)InputTester.cc

ActivityTester.o : $(TES)ActivityTester.h $(TES)ActivityTester.cc $(GA)EvoNetwork.h $(STA)ActivityStater.h $(HAN)Tester.h DefineEDNetwork.h DefineGrapher.h DefineTracer.h DefineStater.h DefineTester.h DefineZoo.h Define.h
	$(GCC) $(TES)ActivityTester.cc

################################################################ Staters ####################################################################

ZooStater.o : $(STA)ZooStater.h $(STA)ZooStater.cc $(HAN)Stater.h $(FH)DistributionGnuplotFile.h $(FH)AccuDataFile.h $(HAN)Accumulater.h $(HAN)Counter.h $(ZOO)Zoo.h $(ZOO)Pacman.h DefineTester.h DefineStater.h DefineZoo.h Define.h
	$(GCC) $(STA)ZooStater.cc

NetworkStater.o : $(STA)NetworkStater.h $(STA)NetworkStater.cc $(HAN)OngoingMeanLogDistribution.h $(HAN)OngoingCumulatedDistribution.h $(HAN)OngoingMeanDistribution.h $(HAN)OngoingDistribution.h $(HAN)MeanLogDistribution.h $(HAN)MeanDistribution.h $(FH)DistributionDataFile.h $(FH)AccuDataFile.h $(HAN)Accumulater.h $(HAN)Counter.h $(EDNN)EDNetwork.h $(STA)LinkedClusterStater.h $(STA)OutputAssemblyStater.h $(STA)InputAssemblyStater.h $(STA)AssemblyStater.h $(STA)LoopStater.h $(HAN)Stater.h DefineGrapher.h DefineTracer.h DefineStater.h DefineEDNetwork.h DefineZoo.h DefineGA.h Define.h
	$(GCC) $(STA)NetworkStater.cc

LinkedClusterStater.o: $(STA)LinkedClusterStater.cc $(STA)LinkedClusterStater.h $(TOPO)LinkedCluster.h $(STA)ClusterStater.h $(HAN)Accumulater.h $(HAN)Counter.h $(TOPO)Assembly.h DefineGrapher.h DefineStater.h DefineEDNetwork.h DefineZoo.h DefineGA.h Define.h
	$(GCC) $(STA)LinkedClusterStater.cc

ClusterStater.o: $(STA)ClusterStater.cc $(STA)ClusterStater.h $(TOPO)Cluster.h $(STA)AssemblyStater.h $(HAN)Accumulater.h $(HAN)Counter.h $(TOPO)Assembly.h DefineGrapher.h DefineStater.h DefineEDNetwork.h DefineZoo.h DefineGA.h Define.h
	$(GCC) $(STA)ClusterStater.cc

InputAssemblyStater.o: $(STA)InputAssemblyStater.h $(STA)InputAssemblyStater.cc $(STA)NeuronStater.h $(HAN)Stater.h $(MPI)InputAssembly.h DefineStater.h Define.h
	$(GCC) $(STA)InputAssemblyStater.cc

OutputAssemblyStater.o: $(STA)OutputAssemblyStater.h $(STA)OutputAssemblyStater.cc $(STA)NeuronStater.h $(HAN)Stater.h $(MPI)OutputAssembly.h DefineStater.h Define.h
	$(GCC) $(STA)OutputAssemblyStater.cc

AssemblyStater.o : $(STA)AssemblyStater.h $(STA)AssemblyStater.cc $(STA)LoopStater.h $(HAN)LogDistribution.h $(HAN)Distribution.h $(HAN)Accumulater.h $(HAN)Counter.h $(TOPO)Assembly.h DefineGrapher.h DefineStater.h DefineEDNetwork.h DefineZoo.h DefineGA.h Define.h
	$(GCC) $(STA)AssemblyStater.cc

LoopStater.o : $(STA)LoopStater.h $(STA)LoopStater.cc $(HAN)MeanDistribution.h $(HAN)LogDistribution.h $(HAN)Distribution.h $(HAN)Counter.h $(HAN)Accumulater.h $(HAN)Stater.h $(DGR)Node.h $(DGR)Link.h DefineStater.h DefineEDNetwork.h Define.h
	$(GCC) $(STA)LoopStater.cc

ActivityStater.o : $(STA)ActivityStater.h $(STA)ActivityStater.cc $(EDNN)EDNetwork.h $(STA)NeuronStater.h $(HAN)Stater.h DefineEDNetwork.h DefineGrapher.h DefineTracer.h DefineStater.h Define.h
	$(GCC) $(STA)ActivityStater.cc

InputStater.o : $(STA)InputStater.h $(STA)InputStater.cc $(EDNN)EDNetwork.h $(STA)NeuronStater.h $(HAN)Stater.h DefineEDNetwork.h DefineGrapher.h DefineTracer.h DefineStater.h Define.h
	$(GCC) $(STA)InputStater.cc

NeuronStater.o:  $(STA)NeuronStater.h $(STA)NeuronStater.cc $(STA)ExcitSynapseStater.h $(STA)InhibSynapseStater.h $(STA)SynapseStater.h $(HAN)Stater.h $(HAN)Accumulater.h $(EDNN)EDNeuron.h DefineTracer.h DefineStater.h DefineEDNetwork.h Define.h
	$(GCC) $(STA)NeuronStater.cc

ExcitSynapseStater.o : $(STA)ExcitSynapseStater.h $(STA)ExcitSynapseStater.cc $(HAN)Stater.h $(HAN)Accumulater.h $(EDNN)EDExcitSynapse.h DefineStater.h DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(STA)ExcitSynapseStater.cc

InhibSynapseStater.o : $(STA)InhibSynapseStater.h $(STA)InhibSynapseStater.cc $(HAN)Stater.h $(HAN)Accumulater.h $(EDNN)EDInhibSynapse.h DefineStater.h DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(STA)InhibSynapseStater.cc

SynapseStater.o : $(STA)SynapseStater.h $(STA)SynapseStater.cc $(HAN)Stater.h $(HAN)Accumulater.h $(EDNN)EDSynapse.h DefineStater.h DefineEDNetwork.h Define.h
	$(GCC) $(STA)SynapseStater.cc

################################################################# Tracers ###################################################################

ZooTracer.o:  $(TRA)ZooTracer.h $(TRA)ZooTracer.cc $(TRA)IndividualTracer.h $(HAN)Tracer.h $(ZOO)Zoo.h DefineTracer.h Define.h
	$(GCC) $(TRA)ZooTracer.cc

IndividualTracer.o: $(TRA)IndividualTracer.h $(TRA)IndividualTracer.cc $(HAN)Tracer.h $(HAN)Grapher.h $(ZOO)Pacman.h DefineZoo.h DefineTracer.h Define.h
	$(GCC) $(TRA)IndividualTracer.cc

NetworkTracer.o: $(TRA)NetworkTracer.h $(TRA)NetworkTracer.cc $(TRA)AssemblyTracer.h $(HAN)Tracer.h $(EDNN)EDNetwork.h DefineEDNetwork.h DefineTracer.h Define.h
	$(GCC) $(TRA)NetworkTracer.cc

AssemblyTracer.o: $(TRA)AssemblyTracer.h $(TRA)AssemblyTracer.cc $(TRA)NeuronTracer.h $(HAN)Tracer.h $(EDNN)EDAssembly.h DefineEDNetwork.h DefineTracer.h Define.h
	$(GCC) $(TRA)AssemblyTracer.cc

NeuronTracer.o: $(TRA)NeuronTracer.h $(TRA)NeuronTracer.cc $(HAN)Tracer.h $(TRA)SynapseTracer.h $(EDNN)EDNeuron.h DefineEDNetwork.h DefineTracer.h Define.h
	$(GCC) $(TRA)NeuronTracer.cc

SynapseTracer.o: $(TRA)SynapseTracer.h $(TRA)SynapseTracer.cc $(HAN)Tracer.h $(EDNN)EDSynapse.h DefineEDNetwork.h DefineTracer.h Define.h
	$(GCC) $(TRA)SynapseTracer.cc


################################################################# Graphers ###################################################################

ZooGrapher.o : $(GRA)ZooGrapher.h $(GRA)ZooGrapher.cc $(HAN)Grapher.h $(GRA)IndividualGrapher.h $(ZOO)Zoo.h DefineTracer.h DefineGrapher.h DefineTracer.h Define.h
	$(GCC) $(GRA)ZooGrapher.cc

IndividualGrapher.o : $(GRA)IndividualGrapher.h $(GRA)IndividualGrapher.cc $(GA)Individual.h $(HAN)Grapher.h DefineTracer.h DefineGrapher.h Define.h
	$(GCC) $(GRA)IndividualGrapher.cc

NetworkGrapher.o : $(GRA)NetworkGrapher.h $(GRA)NetworkGrapher.cc $(GRA)AssemblyGrapher.h $(EDNN)EDNetwork.h DefineTracer.h DefineGrapher.h DefineEDNetwork.h Define.h
	$(GCC) $(GRA)NetworkGrapher.cc

AssemblyGrapher.o : $(GRA)AssemblyGrapher.h $(GRA)AssemblyGrapher.cc $(GRA)NeuronGrapher.h $(EDNN)EDAssembly.h $(HAN)Grapher.h DefineTracer.h DefineGrapher.h DefineEDNetwork.h Define.h
	$(GCC) $(GRA)AssemblyGrapher.cc

NeuronGrapher.o : $(GRA)NeuronGrapher.h $(GRA)NeuronGrapher.cc $(GRA)SynapseGrapher.h $(HAN)Grapher.h $(EDNN)EDNeuron.h DefineTracer.h DefineGrapher.h DefineEDNetwork.h Define.h
	$(GCC) $(GRA)NeuronGrapher.cc

SynapseGrapher.o : $(GRA)SynapseGrapher.h $(GRA)SynapseGrapher.cc $(HAN)Grapher.h $(EDNN)EDSynapse.h DefineTracer.h DefineGrapher.h DefineEDNetwork.h Define.h
	$(GCC) $(GRA)SynapseGrapher.cc

################################################ Event Driven Neural Network ###############################################################

EDNetwork.o: $(EDNN)EDNetwork.cc $(EDNN)EDNetwork.h $(TOPO)Topology.h $(TOPO)LinkedCluster.h $(TOPO)ClusterLink.h $(TOPO)Cluster.h $(EDNN)EDAssembly.h $(MPI)SynchroModule.h $(MPI)InputAssembly.h $(MPI)OutputAssembly.h $(STA)NetworkStater.h $(STA)ClusterStater.h $(STA)ActivityStater.h $(STA)InputStater.h $(INT)Statable.h $(TRA)NetworkTracer.h $(INT)Tracable.h $(GRA)NetworkGrapher.h $(INT)Graphable.h DefineWindow.h DefineStater.h DefineTracer.h $(MT)NeuronMathTools.h DefineGrapher.h DefineEDNetwork.h DefineMPI.h DefineGA.h DefineZoo.h Define.h
	$(GCC) $(EDNN)EDNetwork.cc

EDAssembly.o: $(EDNN)EDAssembly.cc $(EDNN)EDAssembly.h $(INT)Displayable.h $(WIN)TopologyDisplayer.h $(TOPO)Assembly.h $(EDNN)EDNeuron.h $(EDNN)EDExcitProjection.h $(EDNN)EDInhibProjection.h $(MT)RandomMathTools.h $(STA)AssemblyStater.h $(INT)Statable.h $(TRA)AssemblyTracer.h $(INT)Tracable.h $(GRA)AssemblyGrapher.h $(INT)Graphable.h DefineStater.h DefineTracer.h DefineGrapher.h DefineZoo.h DefineEDNetwork.h DefinePhysiology.h  Define.h
	$(GCC) $(EDNN)EDAssembly.cc

EDInhibProjection.o: $(EDNN)EDInhibProjection.cc $(EDNN)EDInhibProjection.h $(TOPO)Projection.h DefineEDNetwork.h Define.h
	$(GCC) $(EDNN)EDInhibProjection.cc

EDExcitProjection.o: $(EDNN)EDExcitProjection.cc $(EDNN)EDExcitProjection.h $(TOPO)Projection.h DefineEDNetwork.h Define.h
	$(GCC) $(EDNN)EDExcitProjection.cc

EDNeuron.o: $(EDNN)EDNeuron.cc $(EDNN)EDNeuron.h $(INT)Displayable.h $(WIN)TopologyDisplayer.h $(INT)Statable.h $(STA)NeuronStater.h $(TRA)NeuronTracer.h $(INT)Tracable.h  $(GRA)NeuronGrapher.h $(INT)Graphable.h $(EDNN)EDInhibSynapse.h $(EDNN)EDExcitSynapse.h $(PHY)SpikingNeuron.h DefineStater.h DefineTracer.h DefineGrapher.h  DefineZoo.h DefineEDNetwork.h DefinePhysiology.h Define.h
	$(GCC) $(EDNN)EDNeuron.cc

EDInhibSynapse.o: $(EDNN)EDInhibSynapse.cc $(EDNN)EDInhibSynapse.h  $(EDNN)EDSynapse.h $(STA)InhibSynapseStater.h DefineStater.h DefineTracer.h DefineGrapher.h DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(EDNN)EDInhibSynapse.cc

EDExcitSynapse.o: $(EDNN)EDExcitSynapse.cc $(EDNN)EDExcitSynapse.h $(EDNN)EDSynapse.h $(STA)ExcitSynapseStater.h DefineStater.h DefineTracer.h DefineGrapher.h  DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(EDNN)EDExcitSynapse.cc

EDSynapse.o: $(EDNN)EDSynapse.cc $(EDNN)EDSynapse.h $(STA)SynapseStater.h $(INT)Statable.h  $(TRA)SynapseTracer.h $(INT)Tracable.h  $(GRA)SynapseGrapher.h $(INT)Graphable.h $(PHY)DynamicSynapse.h $(EDMAN)EventManager.h DefineStater.h DefineTracer.h DefineGrapher.h  DefineZoo.h DefineEDNetwork.h DefinePhysiology.h Define.h
	$(GCC) $(EDNN)EDSynapse.cc

############################################################## Physiology ##################################################################

SpikingNeuron.o: $(PHY)SpikingNeuron.cc $(PHY)SpikingNeuron.h $(TOPO)Neuron.h $(MT)NeuronMathTools.h $(INT)Tracable.h $(TRA)NeuronTracer.h $(PHY)DynamicSynapse.h DefineEDNetwork.h DefinePhysiology.h Define.h
	$(GCC) $(PHY)SpikingNeuron.cc

DynamicSynapse.o: $(PHY)DynamicSynapse.cc $(PHY)DynamicSynapse.h $(TOPO)Synapse.h $(MT)SynapseMathTools.h $(MT)RandomMathTools.h DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(PHY)DynamicSynapse.cc

################################################################ Topology ##################################################################

Topology.o: $(TOPO)Topology.cc $(TOPO)Topology.h $(TOPO)Assembly.h $(INT)Displayable.h $(WIN)TopologyDisplayer.h $(INT)TopoIndexable.h $(OBJ)Object.h DefineEDNetwork.h DefineZoo.h Define.h
	$(GCC) $(TOPO)Topology.cc

LinkedCluster.o: $(TOPO)LinkedCluster.cc $(TOPO)LinkedCluster.h $(STA)LinkedClusterStater.h $(TOPO)Cluster.h DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)LinkedCluster.cc

ClusterLink.o: $(TOPO)ClusterLink.cc $(TOPO)ClusterLink.h $(TOPO)LinkedCluster.h $(DGR)Link.h DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)ClusterLink.cc

Cluster.o: $(TOPO)Cluster.cc $(TOPO)Cluster.h $(STA)ClusterStater.h $(TOPO)Assembly.h $(DGR)Node.h DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)Cluster.cc

Projection.o: $(TOPO)Projection.cc $(TOPO)Projection.h $(TOPO)Assembly.h $(DGR)Link.h DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)Projection.cc

Assembly.o: $(TOPO)Assembly.cc $(TOPO)Assembly.h $(TOPO)Projection.h $(TOPO)Neuron.h $(GRA)AssemblyGrapher.h $(DGR)Node.h  DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)Assembly.cc

Neuron.o: $(TOPO)Neuron.cc $(TOPO)Neuron.h $(TOPO)Synapse.h $(GRA)NeuronGrapher.h $(INT)Displayable.h  $(DGR)Node.h DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)Neuron.cc

Synapse.o: $(TOPO)Synapse.cc $(TOPO)Synapse.h $(TOPO)Neuron.h $(GRA)SynapseGrapher.h $(DGR)Link.h DefineEDNetwork.h Define.h
	$(GCC) $(TOPO)Synapse.cc

################################################################## Event Manager ###########################################################

EventManager.o: $(EDMAN)EventManager.cc $(EDMAN)EventManager.h $(EDNN)EDSynapse.h $(EDMAN)CircledList.h $(EDMAN)PspEventPackage.h DefineEDNetwork.h Define.h
	$(GCC) $(EDMAN)EventManager.cc

CircledList.o: $(EDMAN)CircledList.cc $(EDMAN)CircledList.h $(EDMAN)PreConstructedList.h $(EDMAN)List.h $(OBJ)LinkedObject.h $(OBJ)Object.h
	$(GCC) $(EDMAN)CircledList.cc

PspEventPackage.o: $(EDMAN)PspEventPackage.cc $(EDMAN)PspEventPackage.h $(EDMAN)PreConstructedList.h $(EDMAN)List.h $(OBJ)LinkedObject.h $(OBJ)Object.h
	$(GCC) $(EDMAN)PspEventPackage.cc

List.o: $(EDMAN)List.cc $(EDMAN)List.h $(OBJ)LinkedObject.h $(OBJ)Object.h
	$(GCC) $(EDMAN)List.cc

PreConstructedList.o: $(EDMAN)PreConstructedList.cc $(EDMAN)PreConstructedList.h $(EDMAN)List.h $(OBJ)LinkedObject.h $(OBJ)Object.h
	$(GCC) $(EDMAN)PreConstructedList.cc

################################################################# Math Tools ###############################################################

NeuronMathTools.o: $(MT)NeuronMathTools.cc $(MT)NeuronMathTools.h DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(MT)NeuronMathTools.cc

SynapseMathTools.o: $(MT)SynapseMathTools.cc $(MT)SynapseMathTools.h DefinePhysiology.h DefineEDNetwork.h Define.h
	$(GCC) $(MT)SynapseMathTools.cc

RandomMathTools.o: $(MT)RandomMathTools.cc $(MT)RandomMathTools.h
	$(GCC) $(MT)RandomMathTools.cc

RandomNumberGenerator.o: $(MT)RandomNumberGenerator.cc $(MT)RandomNumberGenerator.h
	$(GCC) $(MT)RandomNumberGenerator.cc

############################################################ Directed Graph ###############################################################
Node.o : $(DGR)Node.cc $(DGR)Node.h $(DGR)Link.h $(STA)LoopStater.h
	$(GCC) $(DGR)Node.cc

Link.o : $(DGR)Link.cc $(DGR)Link.h $(DGR)Node.h
	$(GCC) $(DGR)Link.cc

############################################################## Files #######################################################################

## GnuplotFiles ##

OngoingDistributionGnuplotFile.o: $(FH)OngoingDistributionGnuplotFile.cc $(FH)OngoingDistributionGnuplotFile.h $(FH)DistributionGnuplotFile.h DefineStater.h Define.h
	$(GCC) $(FH)OngoingDistributionGnuplotFile.cc

DistributionGnuplotFile.o: $(FH)DistributionGnuplotFile.cc $(FH)DistributionGnuplotFile.h $(FH)GnuplotFile.h DefineStater.h Define.h
	$(GCC) $(FH)DistributionGnuplotFile.cc

GnuplotFile.o: $(FH)GnuplotFile.cc $(FH)GnuplotFile.h $(OBJ)FileObject.h
	$(GCC) $(FH)GnuplotFile.cc

## DataFiles ##

OngoingDistributionDataFile.o: $(FH)OngoingDistributionDataFile.cc $(FH)OngoingDistributionDataFile.h $(HAN)OngoingMeanLogDistribution.h $(HAN)OngoingCumulatedDistribution.h $(HAN)OngoingMeanDistribution.h $(HAN)OngoingDistribution.h $(FH)DistributionDataFile.h $(FH)AccuDataFile.h $(FH)DataFile.h DefineStater.h Define.h
	$(GCC) $(FH)OngoingDistributionDataFile.cc

DistributionDataFile.o: $(FH)DistributionDataFile.cc $(FH)DistributionDataFile.h $(FH)AccuDataFile.h $(HAN)MeanLogDistribution.h $(HAN)MeanDistribution.h
	$(GCC) $(FH)DistributionDataFile.cc

AccuDataFile.o: $(FH)AccuDataFile.cc $(FH)AccuDataFile.h $(FH)AccuDataFile.h $(HAN)Accumulater.h  DefineStater.h Define.h
	$(GCC) $(FH)AccuDataFile.cc

DataFile.o: $(FH)DataFile.cc $(FH)DataFile.h $(OBJ)FileObject.h
	$(GCC) $(FH)DataFile.cc

IOFile.o: $(FH)IOFile.cc $(FH)IOFile.h $(OBJ)FileObject.h
	$(GCC) $(FH)IOFile.cc

################################################################ Handlers ####################################################################

Tester.o: $(HAN)Tester.h $(HAN)Tester.cc $(HAN)Handler.h $(OBJ)Object.h
	$(GCC) $(HAN)Tester.cc

Stater.o: $(HAN)Stater.h $(HAN)Stater.cc $(HAN)Handler.h $(OBJ)Object.h DefineStater.h
	$(GCC) $(HAN)Stater.cc

Grapher.o : $(HAN)Grapher.h $(HAN)Grapher.cc $(HAN)Handler.h $(OBJ)Object.h
	$(GCC) $(HAN)Grapher.cc

Tracer.o: $(HAN)Tracer.h $(HAN)Tracer.cc $(HAN)Handler.h $(OBJ)Object.h
	$(GCC) $(HAN)Tracer.cc

Displayer.o: $(HAN)Displayer.h $(HAN)Displayer.cc $(INT)Displayable.h $(HAN)Handler.h
	$(GCC) $(HAN)Displayer.cc

Saver.o: $(HAN)Saver.h $(HAN)Saver.cc $(OBJ)Object.h
	$(GCC) $(HAN)Saver.cc

Loader.o: $(HAN)Loader.h $(HAN)Loader.cc $(OBJ)Object.h
	$(GCC) $(HAN)Loader.cc

OngoingMeanLogDistribution.o :  $(HAN)OngoingMeanLogDistribution.cc $(HAN)OngoingMeanLogDistribution.h $(HAN)OngoingMeanDistribution.h $(HAN)MeanLogDistribution.h $(HAN)LogDistribution.h
	$(GCC) $(HAN)OngoingMeanLogDistribution.cc

OngoingCumulatedDistribution.o :  $(HAN)OngoingCumulatedDistribution.cc $(HAN)OngoingCumulatedDistribution.h $(HAN)OngoingMeanDistribution.h $(HAN)CumulatedDistribution.h
	$(GCC) $(HAN)OngoingCumulatedDistribution.cc

OngoingMeanDistribution.o :  $(HAN)OngoingMeanDistribution.cc $(HAN)OngoingMeanDistribution.h $(HAN)MeanDistribution.h $(HAN)OngoingDistribution.h
	$(GCC) $(HAN)OngoingMeanDistribution.cc

OngoingDistribution.o :  $(HAN)OngoingDistribution.cc $(HAN)OngoingDistribution.h $(HAN)MeanDistribution.h $(HAN)Distribution.h
	$(GCC) $(HAN)OngoingDistribution.cc

MeanLogDistribution.o :  $(HAN)MeanLogDistribution.cc $(HAN)MeanLogDistribution.h $(HAN)MeanDistribution.h $(HAN)LogDistribution.h $(HAN)Accumulater.h
	$(GCC) $(HAN)MeanLogDistribution.cc

CumulatedDistribution.o :  $(HAN)CumulatedDistribution.cc $(HAN)CumulatedDistribution.h $(HAN)MeanDistribution.h
	$(GCC) $(HAN)CumulatedDistribution.cc

MeanDistribution.o :  $(HAN)MeanDistribution.cc $(HAN)MeanDistribution.h $(HAN)Distribution.h $(HAN)Accumulater.h
	$(GCC) $(HAN)MeanDistribution.cc

Accumulater.o : $(HAN)Accumulater.cc $(HAN)Accumulater.h $(HAN)Counter.h $(OBJ)Object.h
	$(GCC) $(HAN)Accumulater.cc

LogDistribution.o :  $(HAN)LogDistribution.cc $(HAN)LogDistribution.h $(HAN)Distribution.h
	$(GCC) $(HAN)LogDistribution.cc

Distribution.o :  $(HAN)Distribution.cc $(HAN)Distribution.h $(HAN)Accumulater.h $(HAN)Counter.h
	$(GCC) $(HAN)Distribution.cc

Counter.o : $(HAN)Counter.cc $(HAN)Counter.h $(OBJ)Object.h
	$(GCC) $(HAN)Counter.cc

#Handler.o : $(HAN)Handler.cc $(HAN)Handler.h $(OBJ)Object.h $(INT)EvoIndexable.h $(INT)EvalIndexable.h $(INT)TestIndexable.h $(INT)TopoIndexable.h $(OBJ)IndexedObject.h Define.h
Handler.o : $(HAN)Handler.cc $(HAN)Handler.h $(OBJ)Object.h $(INT)EvoIndexable.h $(INT)EvalIndexable.h $(INT)TestIndexable.h $(INT)TopoIndexable.h $(OBJ)IndexedObject.h
	$(GCC) $(HAN)Handler.cc

################################################################ Interfaces ####################################################################

Statable.o : $(INT)Statable.h $(INT)Statable.cc $(OBJ)Object.h $(HAN)Stater.h
	$(GCC) $(INT)Statable.cc

Displayable.o : $(INT)Displayable.h $(INT)Displayable.cc $(OBJ)Object.h $(HAN)Displayer.h
	$(GCC) $(INT)Displayable.cc

Graphable.o : $(INT)Graphable.h $(INT)Graphable.cc $(OBJ)Object.h $(HAN)Grapher.h
	$(GCC) $(INT)Graphable.cc

Tracable.o : $(INT)Tracable.h $(INT)Tracable.cc $(OBJ)Object.h $(HAN)Tracer.h
	$(GCC) $(INT)Tracable.cc

Testable.o : $(INT)Testable.h $(INT)Testable.cc $(INT)TestIndexable.h $(OBJ)Object.h
	$(GCC) $(INT)Testable.cc

Savable.o : $(INT)Savable.h $(INT)Savable.cc $(OBJ)Object.h $(HAN)Saver.h
	$(GCC) $(INT)Savable.cc

Loadable.o : $(INT)Loadable.h $(INT)Loadable.cc $(OBJ)Object.h $(HAN)Loader.h
	$(GCC) $(INT)Loadable.cc

EvoIndexable.o : $(INT)EvoIndexable.h $(INT)EvoIndexable.cc
	$(GCC) $(INT)EvoIndexable.cc

EvalIndexable.o : $(INT)EvalIndexable.h $(INT)EvalIndexable.cc
	$(GCC) $(INT)EvalIndexable.cc

TestIndexable.o : $(INT)TestIndexable.h $(INT)TestIndexable.cc
	$(GCC) $(INT)TestIndexable.cc

TopoIndexable.o : $(INT)TopoIndexable.h $(INT)TopoIndexable.cc
	$(GCC) $(INT)TopoIndexable.cc

################################################################ Objets ####################################################################

LinkedObject.o: $(OBJ)LinkedObject.cc $(OBJ)LinkedObject.h $(OBJ)Object.h
	$(GCC) $(OBJ)LinkedObject.cc

IndexedObject.o : $(OBJ)IndexedObject.cc $(OBJ)IndexedObject.h $(HAN)Stater.h $(OBJ)Object.h
	$(GCC) $(OBJ)IndexedObject.cc

FileObject.o: $(OBJ)FileObject.cc $(OBJ)FileObject.h $(OBJ)Object.h
	$(GCC) $(OBJ)FileObject.cc

Object.o: $(OBJ)Object.cc $(OBJ)Object.h
	$(GCC) $(OBJ)Object.cc

############################################################################################################################################

