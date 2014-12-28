// .cpp

#include "Include.hpp"
#include "Animation.hpp"

AniSprite::AniSprite()
:	m_Frame(0),
	m_NumFrames(1, 1)
{
}

void AniSprite::SetImage(const sf::Image &Img)
{
	sf::Sprite::SetImage(Img);
	setNumFrames(m_NumFrames);
}

void AniSprite::setSubRectSize(sf::Vector2<unsigned int> &Size)
{
	m_SubRectSize = Size;
	m_NumFrames.x = static_cast<unsigned int>(GetImage()->GetWidth() / Size.x);
	m_NumFrames.y = static_cast<unsigned int>(GetImage()->GetHeight() / Size.y);
	setAniFrame(0);
}

void AniSprite::setNumFrames(sf::Vector2<unsigned int> &Num)
{
	m_NumFrames = Num;
	m_SubRectSize.x = static_cast<unsigned int>(GetImage()->GetWidth() / Num.x);
	m_SubRectSize.y = static_cast<unsigned int>(GetImage()->GetHeight() / Num.y);
	setAniFrame(0);
}

void AniSprite::setAniFrame(sf::Vector2<unsigned int> Frame)
{
	m_Frame = Frame.x * m_NumFrames.y + Frame.y;
	SetSubRect(sf::IntRect(m_SubRectSize.x*Frame.x, m_SubRectSize.y*Frame.y,
						m_SubRectSize.x*(Frame.x+1), m_SubRectSize.y*(Frame.y+1)));
}

void AniSprite::setAniFrame(unsigned int Frame)
{
	setAniFrame(sf::Vector2<unsigned int>(Frame%m_NumFrames.x, Frame/m_NumFrames.x));
}

sf::Rect<float> AniSprite::getRect()
{
	return sf::Rect<float>(GetPosition().x - GetCenter().x, GetPosition().y - GetCenter().y,
							GetPosition().x - GetCenter().x + GetSize().x, GetPosition().y - GetCenter().y + GetSize().y);
}

void TimeAniSprite::update(float Frametime)
{
	m_FrameTime += Frametime*m_FPS;
	if(m_FrameTime > getNumFrames())
		m_FrameTime -= getNumFrames();
	setAniFrame(static_cast<unsigned int>(m_FrameTime));
}

void TimeAniSpritePause::randomFrame()
{
	float Pause = m_PauseTime + getNumFrames()/m_FPS;
	m_CurrentPauseTime = sf::Randomizer::Random(0.f , m_PauseTime);
	if(m_CurrentPauseTime >= m_PauseTime)
	{
		m_FrameTime = (m_CurrentPauseTime - m_PauseTime)*m_FPS;
		setAniFrame(static_cast<unsigned int>(m_FrameTime));
		m_CurrentPauseTime = 0.f;
	}
	else
	{
		m_FrameTime = getNumFrames()+1.f;
		setAniFrame(0);
	}
}

void TimeAniSpritePause::update(float Frametime)
{
	if(m_FrameTime < getNumFrames())
	{
		m_FrameTime += Frametime*m_FPS;
		setAniFrame(static_cast<unsigned int>(m_FrameTime));
	}

	if(m_FrameTime >= getNumFrames())
	{
		setAniFrame(0);
		m_CurrentPauseTime += Frametime;
		if(m_CurrentPauseTime > m_PauseTime)
		{
			m_CurrentPauseTime = 0.f;
			m_FrameTime = 0.f;
		}
	}
}