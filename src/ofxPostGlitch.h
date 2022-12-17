//
//  ofxPostGlitch.h
//
//  Created by maxilla inc. on 2013/02/01.
//
//

#ifndef __ofxPostGlitchExample__ofxPostGlitch__
#define __ofxPostGlitchExample__ofxPostGlitch__

#include "ofMain.h"

#define GLITCH_NUM 15

enum ofxPostGlitchType{
	OFXPOSTGLITCH_CONVERGENCE,
	OFXPOSTGLITCH_SHAKER,
	OFXPOSTGLITCH_CUTSLIDER,
	OFXPOSTGLITCH_TWIST,
	OFXPOSTGLITCH_OUTLINE,
	OFXPOSTGLITCH_SLITSCAN,
	OFXPOSTGLITCH_SWELL,
	OFXPOSTGLITCH_INVERT,
	OFXPOSTGLITCH_CR_HIGHCONTRAST,
	OFXPOSTGLITCH_CR_BLUERAISE,
	OFXPOSTGLITCH_CR_REDRAISE,
	OFXPOSTGLITCH_CR_GREENRAISE,
	OFXPOSTGLITCH_CR_REDINVERT,
	OFXPOSTGLITCH_CR_BLUEINVERT,
	OFXPOSTGLITCH_CR_GREENINVERT
};

class ofxPostGlitch{
public:

	ofxPostGlitch(){
		
		targetBuffer = NULL;

	if(ofIsGLProgrammableRenderer()){
		shader[0].load("shaders/gl3/convergence");
		shader[1].load("shaders/gl3/shaker");
		shader[2].load("shaders/gl3/cut_slider");
		shader[3].load("shaders/gl3/twist");
		shader[4].load("shaders/gl3/outline");
		shader[5].load("shaders/gl3/slitscan");
		shader[6].load("shaders/gl3/swell");
		shader[7].load("shaders/gl3/invert");
		shader[8].load("shaders/gl3/crHighContrast");
		shader[9].load("shaders/gl3/crBlueraise");
		shader[10].load("shaders/gl3/crRedraise");
		shader[11].load("shaders/gl3/crGreenraise");
		shader[12].load("shaders/gl3/crRedinvert");
		shader[13].load("shaders/gl3/crBlueinvert");
		shader[14].load("shaders/gl3/crGreeninvert");
	}else{
		shader[0].load("shaders/gl2/convergence");
		shader[1].load("shaders/gl2/shaker");
		shader[2].load("shaders/gl2/cut_slider");
		shader[3].load("shaders/gl2/twist");
		shader[4].load("shaders/gl2/outline");
		shader[5].load("shaders/gl2/slitscan");
		shader[6].load("shaders/gl2/swell");
		shader[7].load("shaders/gl2/invert");
		shader[8].load("shaders/gl2/crHighContrast");
		shader[9].load("shaders/gl2/crBlueraise");
		shader[10].load("shaders/gl2/crRedraise");
		shader[11].load("shaders/gl2/crGreenraise");
		shader[12].load("shaders/gl2/crRedinvert");
		shader[13].load("shaders/gl2/crBlueinvert");
		shader[14].load("shaders/gl2/crGreeninvert");
		}
	}

	/* Initialize & set target Fbo */
	void setup(ofFbo* buffer_);

	/* Set target Fbo */
	void setFbo(ofFbo* buffer_);

	/* Switch each effects on/off */
	void setFx(ofxPostGlitchType type_,bool enabled);

	/* Toggle each effects on/off */
	void toggleFx(ofxPostGlitchType type_);

	/* Return current effect's enabled info*/
	bool getFx(ofxPostGlitchType type_);

	/* Apply enable effects to target Fbo */
	void generateFx();

protected:
	bool		bShading[GLITCH_NUM];
	ofShader	shader[GLITCH_NUM];
	ofFbo*		targetBuffer;
	ofFbo		ShadingBuffer;
	ofPoint		buffer_size;
	float ShadeVal[4];
};

#endif /* defined(__ofxPostGlitchExample__ofxPostGlitch__) */
