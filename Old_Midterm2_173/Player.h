

#pragma once

#include "graphics.h"

class Player
{
public:
	Player() {};
	Player(int x_pos, int y_pos, int size);

	void draw();
	void moveLeft(int WINDOW_WIDTH);
	void moveRight(int WINDOW_WIDTH);

	//void shoot();

	int getXPos() const;
	void setXPos(int x_pos);
	int getYPos() const;
	void setYPos(int y_pos);

	int getSize();

private:

	int poly[12];
	int x_ref_pos_;
	int y_ref_pos_;
	int size_;

};

Player::Player(int x_pos, int y_pos, int size)
{
	x_ref_pos_ = x_pos;
	y_ref_pos_ = y_pos;
	size_ = size;

	poly[0] = x_ref_pos_ + size / 2;
	poly[1] = y_ref_pos_;

	poly[2] = x_ref_pos_;
	poly[3] = y_ref_pos_ + size / 2;

	poly[4] = x_ref_pos_ + size * 0.25;
	poly[5] = y_ref_pos_ + size;

	poly[6] = x_ref_pos_ + size * 0.75;
	poly[7] = y_ref_pos_ + size;

	poly[8] = x_ref_pos_ + size;
	poly[9] = y_ref_pos_ + size / 2;

	poly[10] = x_ref_pos_ + size / 2;
	poly[11] = y_ref_pos_;

}

void Player::draw()
{
	setfillstyle(1, 15);
	fillpoly(6, poly);
}

void Player::moveLeft(int WINDOW_WIDTH)
{
	if (x_ref_pos_ >= 0)
	{
		x_ref_pos_ -= 10;

		poly[0] = x_ref_pos_ + size_ / 2;
		poly[1] = y_ref_pos_;

		poly[2] = x_ref_pos_;
		poly[3] = y_ref_pos_ + size_ / 2;

		poly[4] = x_ref_pos_ + size_ * 0.25;
		poly[5] = y_ref_pos_ + size_;

		poly[6] = x_ref_pos_ + size_ * 0.75;
		poly[7] = y_ref_pos_ + size_;

		poly[8] = x_ref_pos_ + size_;
		poly[9] = y_ref_pos_ + size_ / 2;

		poly[10] = x_ref_pos_ + size_ / 2;
		poly[11] = y_ref_pos_;
	}
}

void Player::moveRight(int WINDOW_WIDTH)
{
	if (x_ref_pos_ + size_ <= WINDOW_WIDTH)
	{
		x_ref_pos_ += 10;

		poly[0] = x_ref_pos_ + size_ / 2;
		poly[1] = y_ref_pos_;

		poly[2] = x_ref_pos_;
		poly[3] = y_ref_pos_ + size_ / 2;

		poly[4] = x_ref_pos_ + size_ * 0.25;
		poly[5] = y_ref_pos_ + size_;

		poly[6] = x_ref_pos_ + size_ * 0.75;
		poly[7] = y_ref_pos_ + size_;

		poly[8] = x_ref_pos_ + size_;
		poly[9] = y_ref_pos_ + size_ / 2;

		poly[10] = x_ref_pos_ + size_ / 2;
		poly[11] = y_ref_pos_;
	}
		
}

int Player::getXPos() const
{
	return x_ref_pos_;
}

int Player::getYPos() const
{
	return y_ref_pos_;
}


int Player::getSize()
{
	return size_;
}

