
const char* msg_to_user(int num_tries)
{
	const int rsp_cnt = 5;
	static const char* usr_msgs[rsp_cnt] = {
		"go on, make a guess.",
		"Opps! Nice gurss but not quite it.",
		"Hmmm, sorry. Wrong a second time.",
		"Ah, this is harder than it looks, no?",
		"It must be getting pretty frustrating by now!"
	};

	if (num_tries < 0)
		num_tries = 0;
	else if (num_tries >= rsp_cnt)
		num_tries = rsp_cnt - 1;
	return usr_msgs[num_tries];
}

