#ifndef ANIMATIONSPRITE_H
#define ANIMATIONSPRITE_H

#include "Include.hpp"

class AniSprite : public sf::Sprite
{
	unsigned int m_Frame;
	sf::Vector2<unsigned int> m_SubRectSize;
	sf::Vector2<unsigned int> m_NumFrames;
public:
	AniSprite();
	void SetImage(const sf::Image &Img);
	void setSubRectSize(sf::Vector2<unsigned int> &Size);
	void setNumFrames(sf::Vector2<unsigned int> &Num);
	void setAniFrame(unsigned int Frame);
	void setAniFrame(sf::Vector2<unsigned int> Frame);
	inline unsigned int getNumFrames(){return m_NumFrames.x*m_NumFrames.y;}
	inline unsigned int getAniPhase(){return m_Frame;};
	sf::Rect<float> getRect();
};

class TimeAniSprite : public AniSprite
{
protected:
	float m_FrameTime;
	float m_FPS;
public:
	TimeAniSprite(float FPS)
		: m_FPS(FPS), m_FrameTime(NULL)
	{}
	TimeAniSprite(const TimeAniSprite& sprite)
		: m_FPS(sprite.m_FPS), m_FrameTime(sprite.m_FrameTime)
	{
		*this = sprite;
	}
	void randomFrame(){m_FrameTime = static_cast<float>(sf::Randomizer::Random(0 ,getNumFrames()-1));}
	void setFPS(float FPS){m_FPS = FPS;}
	void update(float Frametime);
};

class TimeAniSpritePause : public TimeAniSprite
{
private:
	float m_PauseTime;
	float m_CurrentPauseTime;
public:
	TimeAniSpritePause(const float FPS, const float Pause)
		: TimeAniSprite(FPS), m_PauseTime(Pause), m_CurrentPauseTime(0.f)
	{
	}
	void randomFrame();
	void update(float Frametime);
};

#endif