

#pragma once


#include "graphics.h"

class Ball
{
public:
	Ball();
	Ball(int x_pos, int y_pos, int x_vel, int y_vel, int radius, int color);
	void move_ball();
	void draw() const;

	int getXPos() const;
	void setXPos(int x_pos);

	int getYPos() const;
	void setYPos(int y_pos);

	int getXVelocity() const;
	void setXVelocity(int x_vel);

	int getYVelocity() const;
	void setYVelocity(int y_vel);

	int getRadius();
	void setRadius(int radius);

	void border_coliision(int WINDOW_WIDTH, int WINDOW_HEIGHT);

	bool isOffScreen(int WINDOW_WIDTH, int WINDOW_HEIGHT);

protected:
	int x_;
	int y_;
	int radius_;
	int color_;
	int x_velocity_;
	int y_velocity_;

};

void Ball::move_ball()
{
	x_ += x_velocity_;
	y_ += y_velocity_;
}

void Ball::draw() const
{
	setcolor(color_);
	setfillstyle(SOLID_FILL, color_);
	fillellipse(x_, y_, radius_, radius_);
}

Ball::Ball(int x_pos, int y_pos, int x_vel, int y_vel, int radius, int color)
{
	x_ = x_pos;
	y_ = y_pos;
	x_velocity_ = x_vel;
	y_velocity_ = y_vel;
	radius_ = radius;
	color_ = color;
}

Ball::Ball()
{
	srand(GetTickCount());
	
	const int MAX_RADIUS = 50;
	const int MIN_RADIUS = 10;

	radius_ = rand() % (MAX_RADIUS - MIN_RADIUS) + MIN_RADIUS;

	x_ = rand() % 2 * MIN_RADIUS + MIN_RADIUS;
	y_ = rand() % 2 * MIN_RADIUS + MIN_RADIUS;
	color_ = RGB(rand() % 256, rand() % 256, rand() % 256);

	x_velocity_ = rand() % 30;
	y_velocity_ = rand() % 30;
}


int Ball::getXPos() const
{
	return x_;
}

void Ball::setXPos(int x_pos)
{
	x_ = x_pos;
}

int Ball::getYPos() const
{
	return y_;
}

void Ball::setYPos(int y_pos)
{
	y_ = y_pos;
}

int Ball::getXVelocity() const
{
	return x_velocity_;
}

void Ball::setXVelocity(int x_vel)
{
	x_velocity_ = x_vel;
}

int Ball::getYVelocity() const
{
	return y_velocity_;
}

void Ball::setYVelocity(int y_vel)
{
	y_velocity_ = y_vel;
}

void Ball::setRadius(int radius)
{
	radius_ = radius;
}

int Ball::getRadius()
{
	return radius_;
}


void Ball::border_coliision(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
	if (x_ + radius_ >= WINDOW_WIDTH || x_ - radius_ <= 0)
	{
		x_velocity_ = -x_velocity_;
	}

	if (y_ + radius_ >= WINDOW_HEIGHT || y_ - radius_ <= 0)
	{
		y_velocity_ = -y_velocity_;
	}

}


bool Ball::isOffScreen(int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
	if (x_ >= radius_ + WINDOW_WIDTH || x_ + radius_ <= 0
		|| y_ >= radius_ + WINDOW_HEIGHT || y_ + radius_ <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}







