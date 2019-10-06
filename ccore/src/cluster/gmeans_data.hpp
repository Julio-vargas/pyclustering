/**
*
* @authors Andrei Novikov (pyclustering@yandex.ru)
* @date 2014-2019
* @copyright GNU Public License
*
* GNU_PUBLIC_LICENSE
*   pyclustering is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   pyclustering is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#pragma once


#include <memory>
#include <vector>

#include "cluster/cluster_data.hpp"

#include "definitions.hpp"


namespace ccore {

namespace clst {


/**
*
* @brief    Clustering results of G-Means algorithm that consists of information about allocated
*           clusters and centers of each cluster.
*
*/
class gmeans_data : public cluster_data {
private:
    dataset       m_centers   = { };

    double        m_wce       = 0.0;

public:
    /**
    *
    * @brief    Default constructor that creates empty clustering data.
    * @details  In case of default constructor clusters and centers are not stored on each clustering iteration.
    *
    */
    gmeans_data(void) = default;

    /**
    *
    * @brief    Copy constructor that creates clustering data that is the same to specified.
    *
    * @param[in] p_other: another clustering data.
    *
    */
    gmeans_data(const gmeans_data & p_other) = default;

    /**
    *
    * @brief    Move constructor that creates clustering data from another by moving data.
    *
    * @param[in] p_other: another clustering data.
    *
    */
    gmeans_data(gmeans_data && p_other) = default;

    /**
    *
    * @brief    Default destructor that destroys clustering data.
    *
    */
    virtual ~gmeans_data(void) = default;

public:
    /**
    *
    * @brief    Returns reference to centers that correspond to allocated clusters.
    *
    */
    dataset & centers(void) { return m_centers; }

    /**
    *
    * @brief    Returns constant reference to centers that correspond to allocated clusters.
    *
    */
    const dataset & centers(void) const { return m_centers; };

    /**
    *
    * @brief    Returns total within-cluster errors.
    *
    */
    double & wce(void) { return m_wce; }

    /**
    *
    * @brief    Returns constant total within-cluster errors.
    *
    */
    const double & wce(void) const { return m_wce; }
};


}

}