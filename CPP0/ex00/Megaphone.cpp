#include <string>
#include <iostream>

class	Megaphone {
	public:
		std::string	amplify(char *message) {
			std::string	outMessage = "";
			for (unsigned long int i = 0; message[i] != '\0'; i++)
				outMessage += std::toupper(message[i]);
			return (outMessage);
		}

		std::string	whiteNoise(void) {
			return ("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		}
};

int	main(int argc, char *argv[])
{
	Megaphone	megaphone;

	if (argc == 1)
		std::cout << megaphone.whiteNoise() << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
			std::cout << megaphone.amplify(argv[i]);
	}
	std::cout << std::endl;
}