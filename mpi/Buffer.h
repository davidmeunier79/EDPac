// Buffer.h

#ifndef _BUFFER_H
#define _BUFFER_H

//#include <mpi++.h>
// Special lam 7.0
#include <mpi.h>
#include <vector>
using namespace std;

// Local Includes
#include "GenericBuffer.h"

// classe permettant de stocker les messages a envoyer/recevoir
// le template sert a indiquer le type du message (MPI_CHAR par exemple)
// l'utilisateur est reponsable de la verification de la compatibilite des envois/receptions
template<class C_type,const MPI::Datatype & MPI_type>
class Buffer : public GenericBuffer
{
protected :
	int size;
	C_type *message;

public :

	Buffer();
	Buffer(int newSize);
	Buffer(int newSize,int newTag);
	
	//virtual Buffer* clone()=0;

	~Buffer();

		// Communicateur COMM_WORLD

	// envoi non bloquant aux recepteurs
	void sendMessage(int recepteur);

	// envoi nul non bloquant aux recepteurs
	void sendVoidMessage(int recepteur);

	// envoi BREAK aux recepteurs
	void sendBreakMessage(int recepteur);
	
	// envoi SKIP aux recepeteurs
	void sendSkipMessage(int recepteur);

	// reception non bloquante d'un messge de emetteur
	void receiveMessage(int emetteur);

	// Initialisation des requetes persistentes
	void initReceive(int emetteur);
	void initSend(int emetteur);

		// Gestion des messages

	// consulter/modifier les attributs
	void setMessage(const vector<C_type>&);

	// Information sur le status
	int getCount();

	C_type & operator[](int i);
	void setSize(int taille2);
	int getSize();
};

typedef Buffer<double,MPI::DOUBLE> MPIBuffer;
//typedef Buffer<int,MPI::INT> IntBuffer;

/********************************************************************************************/
/*                                                                                          */
/*                   Definitions des methodes de Buffer                                     */
/*                                                                                          */
/********************************************************************************************/


template<class C_type,const MPI::Datatype & MPI_type>
Buffer<C_type,MPI_type>::Buffer(): GenericBuffer(), size(0), message(0)
{
}

template<class C_type,const MPI::Datatype & MPI_type>
Buffer<C_type,MPI_type>::Buffer(int newSize): GenericBuffer(), size(newSize)
{
  	message=new C_type[size];
}

template<class C_type,const MPI::Datatype & MPI_type>
Buffer<C_type,MPI_type>::Buffer(int newSize,int newTag): GenericBuffer(newTag),size(newSize)
{
	message=new C_type[size];
}

template<class C_type,const MPI::Datatype & MPI_type>
Buffer<C_type,MPI_type>::~Buffer()
{
  	if(message)
	{
		delete message;
	}
}
	// COMM_WORLD

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::sendMessage(int recepteur)
{
  flag=0;
  request=MPI::COMM_WORLD.Isend(static_cast<void*>(message),size,MPI_type,recepteur,tag);
}

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::sendVoidMessage(int recepteur)
{
  flag=0;
  message[0]=VOID;
  request=MPI::COMM_WORLD.Isend(static_cast<void*>(message),1,MPI_type,recepteur,tag);
}

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::sendBreakMessage(int recepteur)
{
  flag=0;
  message[0]=BREAK;
  request=MPI::COMM_WORLD.Isend(static_cast<void*>(message),1,MPI_type,recepteur,tag);
}

void sendSkipMessage(int recepteur);

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::sendSkipMessage(int recepteur)
{
  flag=0;
  message[0]=SKIP;
  request=MPI::COMM_WORLD.Isend(static_cast<void*>(message),1,MPI_type,recepteur,tag);
}


template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::receiveMessage(int emetteur)
{
  flag=0;
  request=MPI::COMM_WORLD.Irecv(message,size,MPI_type,emetteur,tag);
}

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::initReceive(int emetteur)
{
  flag=0;
  request=MPI::COMM_WORLD.Recv_init(message,size,MPI_type,emetteur,tag);
}

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::initSend(int recepteur)
{
  flag=0;
  request=MPI::COMM_WORLD.Send_init(static_cast<void*>(message),size,MPI_type,recepteur,tag);
}

	// Gestion des messages
template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::setMessage(const vector<C_type> & aCopier)
{
  setSize(aCopier.size());
  for(int i=0;i<size;i++)
    message[i]=aCopier[i];
}

template<class C_type,const MPI::Datatype & MPI_type>
int Buffer<C_type,MPI_type>::getCount()
{
	if (flag)
	{
		int count = status.Get_count(MPI_type);
#ifdef _MPI_TEST
		cout << "Returning status compt " << count << endl;
#endif
		return (count);
	}
}

template<class C_type,const MPI::Datatype & MPI_type>
C_type & Buffer<C_type,MPI_type>::operator[](int i)
{
  return message[i];
}

template<class C_type,const MPI::Datatype & MPI_type>
void Buffer<C_type,MPI_type>::setSize(int newSize)
{
  if(size!=newSize)
    {
      size=newSize;
      if(message)
	delete [] message;
      message=new C_type [size];
    }
}

template<class C_type,const MPI::Datatype & MPI_type>
int Buffer<C_type,MPI_type>::getSize()
{
  return size;
}

#endif

