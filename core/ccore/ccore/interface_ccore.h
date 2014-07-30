#ifndef _INTERFACE_CCORE_H_
#define _INTERFACE_CCORE_H_

typedef struct cluster_representation {
	unsigned int			size;
	unsigned int			* objects;
} cluster_representation;

typedef struct clustering_result {
	unsigned int			size;
	cluster_representation	* clusters;
} clustering_result;

typedef struct data_representation {
	unsigned int			size;
	unsigned int			dimension;
	double					** objects;
} data_representation;

typedef struct dynamic_result {
	unsigned int			size_dynamic;
	unsigned int			size_network;
	double					* times;
	double					** dynamic;
} dynamic_result;

extern "C" __declspec(dllexport) void free_clustering_result(clustering_result * pointer);

extern "C" __declspec(dllexport) clustering_result * dbscan_algorithm(const data_representation * const sample, const double radius, const unsigned int minumum_neighbors);

extern "C" __declspec(dllexport) clustering_result * hierarchical_algorithm(const data_representation * const sample, const unsigned int number_clusters);

extern "C" __declspec(dllexport) clustering_result * kmeans_algorithm(const data_representation * const sample, const data_representation * const initial_centers, const double tolerance);

extern "C" __declspec(dllexport) clustering_result * rock_algorithm(const data_representation * const sample, const double radius, const unsigned int number_clusters, const double threshold);

extern "C" __declspec(dllexport) void free_dynamic_result(dynamic_result * pointer);

extern "C" __declspec(dllexport) void destroy_object(void * object);




/***********************************************************************************************
 *
 * @brief   Create oscillatory network Sync that is based on Kuramoto model.
 *
 * @param   (in) size				- number of oscillators in the network.
 *          (in) weight_factor		- coupling strength of the links between oscillators.
 *          (in) frequency_factor	- multiplier of internal frequency of the oscillators.
 *          (in) qcluster			- number of artificial clustering during synchronization.
 *          (in) connection_type	- type of connection between oscillators in the network.
 *          (in) initial_phases		- type of initialization of initial phases of oscillators.
 *
 ***********************************************************************************************/
extern "C" __declspec(dllexport) void * create_sync_network(const unsigned int size, const double weight_factor, const double frequency_factor, const unsigned int qcluster, const unsigned int connection_type, const unsigned int initial_phases);

/***********************************************************************************************
 *
 * @brief   Simulate dynamic of the oscillatory Sync network.
 *
 * @param   (in) pointer_network	- pointer to the Sync network.
 *          (in) steps				- number steps of simulations during simulation.
 *          (in) time				- time of simulation.
 *          (in) solver				- type of solution (solving).
 *          (in) collect_dynamic	- true - returns whole dynamic of oscillatory network, 
 *                                    otherwise returns only last values of dynamics.
 *
 * @return	Returns dynamic of simulation of the network.
 *
 ***********************************************************************************************/
extern "C" __declspec(dllexport) dynamic_result * simulate_sync_network(const void * pointer_network, unsigned int steps, const double time, const unsigned int solver, const bool collect_dynamic);

/***********************************************************************************************
 *
 * @brief   Allocate clusters in line with ensembles of synchronous oscillators where each
 *          synchronous ensemble corresponds to only one cluster.
 *
 * @param   (in) pointer_network	- pointer to the Sync network.
 *          (in) tolerance			- maximum error for allocation of synchronous ensemble 
 *                                    oscillators.
 *
 * @return	Returns ensembles of synchronous oscillators as clustering result.
 *
 ***********************************************************************************************/
extern "C" __declspec(dllexport) clustering_result * allocate_sync_ensembles(const void * pointer_network, const double tolerance);

#endif