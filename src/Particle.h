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

	double m_speed; //how fast a particle is moving
	double m_direction; //angle from 0 to 360 degrees


public:
	void update(int interval);
	Particle();
	virtual ~Particle();
};

} /* namespace cop */

#endif /* PARTICLE_H_ */
