/*
 * Particle.h
 *
 *  Created on: 9 May 2017
 *      Author: Raja
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace cop {

struct Particle {
	double m_x;
	double m_y;
	double m_xspeed;
	double m_yspeed;


public:
	void update();
	Particle();
	virtual ~Particle();
};

} /* namespace cop */

#endif /* PARTICLE_H_ */
