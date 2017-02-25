

class Motor{
	public:
		int IN1;
		int IN2;
		int PWM;
		int speed;
		bool inverted;

		Motor();
		void init(int defPWM, int defIN1, int defIN2, int defSpeed, bool defInverted);
};
