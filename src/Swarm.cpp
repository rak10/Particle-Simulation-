/*
 * Swarm.cpp
 *
 *  Created on: 9 May 2017
 *      Author: Raja
 */

#include "Swarm.h"

namespace cop {

Swarm::Swarm() {

	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

} /* namespace cop */
