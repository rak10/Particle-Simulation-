/*
 * Particle.cpp
 *
 *  Created on: 9 May 2017
 *      Author: Raja
 */

#include "Particle.h"
#include <stdlib.h>
namespace cop {

Particle::Particle() {

	m_x = ((2.0 * rand())/RAND_MAX) - 1;
	m_y = ((2.0 * rand())/RAND_MAX) - 1;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace cop */
