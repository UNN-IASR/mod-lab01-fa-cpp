unsigned int faStr2(const char* str) {
	if (str == "")
	{
		return 0;
	}
	bool startworld = false;
	int count_worlds = 0;
	for (const char* p = str; *p; p++)
	{
		if (*p != ' ')
		{
			if (*p >= 'A' && *p <= 'Z')
			{
				if (!startworld)
				{
					startworld = true;
				}
				else {
					startworld = false;
					while (*p != ' ' && *p != 0)
					{
						p++;
					}
				}
			}
			else
			{
				if (*p >= 'a' && *p <= 'z') {
					if (!startworld)
					{
						while (*p != ' ' && *p != 0)
						{
							p++;
						}
					}

				}
				else {
					startworld = false;
				}

			}

			if ('0' <= *p && *p <= '9')
			{
				startworld = false;
				while (*p != ' ' && *p != 0)
				{
					p++;
				}
			}

		}
		else
		{
			if (startworld)
			{
				startworld = false;
				count_worlds++;
			}
		}

	}
	if (startworld)
	{
		startworld = false;
		count_worlds++;
	}
	return count_worlds;
}
