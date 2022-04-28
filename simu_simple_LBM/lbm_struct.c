/********************  HEADERS  *********************/
#include <stdlib.h>
#include "lbm_struct.h"

/*******************  FUNCTION  *********************/
/**
 * Fonction d'initialisation du maillage local.
 * @param mesh Maillage à initialiser.
 * @param width Taille du maillage, mailles fantomes comprises.
 * @param height Taille du maillage, mailles fantomes comprises.
**/
void Mesh_init( Mesh * mesh, int width,  int height )
{
	//setup params
	mesh->width = width;
	mesh->height = height;

	//alloc cells memory
	mesh->cells = calloc( width * height  * DIRECTIONS, sizeof( double ) );

	//errors
	/*if( mesh->cells == NULL )
	{
		perror( "malloc" );
		abort();
	}*/
}

/*******************  FUNCTION  *********************/
/** Libère la mémoire d'un maillage. **/
void Mesh_release( Mesh *mesh )
{
	//free memory
	free( mesh->cells);
}

/*******************  FUNCTION  *********************/
/**
 * Fonction d'initialisation du maillage local.
 * @param mesh Maillage à initialiser.
 * @param width Taille du maillage, mailles fantomes comprises.
 * @param height Taille du maillage, mailles fantomes comprises.
**/
void lbm_mesh_type_t_init( lbm_mesh_type_t * meshtype, int width,  int height )
{
	//alloc cells memory
	meshtype->types = calloc( width  * height , sizeof( lbm_cell_type_t ) );
}

/*******************  FUNCTION  *********************/
/** Libère la mémoire d'un maillage. **/
void lbm_mesh_type_t_release( lbm_mesh_type_t * mesh )
{
	free( mesh->types );
}

/*******************  FUNCTION  *********************/
void fatal(const char * message)
{
	fprintf(stderr,"FATAL ERROR : %s\n",message);
	abort();
}
