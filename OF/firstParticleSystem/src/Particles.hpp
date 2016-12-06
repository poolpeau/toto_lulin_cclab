//
//  Particles.hpp
//  firstParticleSystem
//
//  Created by TtTtTtTtT on 03/11/16.
//
//

#ifndef Particles_hpp
#define Particles_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle {
public:
    
    Particle(ofVec2f pos);
    
    void resetForces();
    void applyForce(ofVec2f force);
    void update (float multiplier);
    void draw ();
    
    ofVec2f mPosition, mVelocity, mAcceleration;
    float mlifeSpan;
    const float INITIAL_LIFE_SPAN = 120.0f;
    const float BLINKING_LIFE_SPAN = 60.0f;
    
    
    
}

#endif /* Particles_hpp */
