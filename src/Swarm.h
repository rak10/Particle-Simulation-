/*
 * Swarm.h
 *
 *  Created on: 9 May 2017
 *      Author: Raja
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"
namespace cop {

class Swarm {
private:
	Particle *m_pParticles;
	int lastTime;


public:
	const static int NPARTICLES = 5000;
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles() { return m_pParticles; };
	void update(int elapsed);
};

} /* namespace cop */

#endif /* SWARM_H_ */
