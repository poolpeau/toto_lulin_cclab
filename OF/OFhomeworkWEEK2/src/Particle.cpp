//
//  Particle.cpp
//  FirstParticleSystem
//
//  Created by Toto L on 11/3/16.
//
//

#include "Particle.hpp"

Particle::Particle(ofVec2f pos) {
    
    mPosition = pos;
    mVelocity = ofVec2f(ofRandom(-10.f, 2.f), ofRandom(-2.f, 10.f));
    mAcceleration = ofVec2f(0, 0);
    mLifeSpan = INITIAL_LIFE_SPAN;
    
}

void Particle::resetForces() {
    
    mAcceleration *= 4.0;
    
}

void Particle::applyForce(ofVec2f force) {
    
    mAcceleration += force;
    
}

void Particle::update(float multiplier) {
    
    // apply acceleration to velocity
    mVelocity += mAcceleration/2;
    mPosition += mVelocity * multiplier;
    
    // decrease the particle life
    if (mLifeSpan > 0) {
        mLifeSpan -= 0.001f;
    } else {
        mLifeSpan+=30.f;
}
    
    
    
}

void Particle::draw() {
    
    if(mLifeSpan > BLINKING_LIFE_SPAN) {
        // new born particle will be brighter
      
        ofSetColor(255,200,200);
        ofNoFill();
        
    } else {
        // do some sparkle!
        ofSetColor(ofRandom(0, mLifeSpan/INITIAL_LIFE_SPAN * 255));
    }
    
    ofDrawCircle(mPosition, 2.0f * ofMap(mLifeSpan, 0, 255.f, 0, 100.f));

    }
    
