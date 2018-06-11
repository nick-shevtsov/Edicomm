#pragma once

#include <string> // підключення бібліотеки
    class Comsedit
    {
    // відкритий модифікатор доступу                                            
    public:
        /* Булеві змінні.
        Параметри.                     
        Відповідають за форматування. */ 
        static bool singleLine;
        static bool singleRemove;
        static bool multiLine;      
        static bool multiRemove;
        static bool emptyRemove;
        // отримати екземпляр
        static Comsedit& Instance() {
            static Comsedit comsedit;
            return comsedit;
        }
        // функція перетворення тексту
        static void Compress(std::string& dest, std::string& src) {
            if (singleLine || multiLine || emptyRemove)
            {
                int strLength = src.length();
                int state = 0;
                char c;
                char tmpc;
                bool isNewLine = true;
                bool isMultiLine = false;
                dest.clear();
                std::string tmpdest;
                for (int i = 0; i < strLength; i++)
                {
                    c = src[i];
                    switch (state)
                    {
                    case 0: {
                        switch (c)
                        {
                        case '/':
                            state = 1;
                            tmpc = c;
                            break;
                        case '"':
                            state = 5;
                            isNewLine = false;
                            isMultiLine = false;
                            if (!tmpdest.empty())
                            {
                                dest += tmpdest;
                                tmpdest.clear();
                            }
                            dest.push_back(c);
                            break;
                        case ' ':
                        case '\t':
                            tmpdest.push_back(c);
                            break;
                        case '\r':
                            break;
                        case '\n':
                            if (!(isNewLine && !(emptyRemove && !isMultiLine) ^ !(isMultiLine && multiRemove)))
                            {
                                dest.push_back('\r');
                                dest.push_back(c);
                            }
                            if (!tmpdest.empty())
                                tmpdest.clear();
                            isMultiLine = false;
                            isNewLine = true;
                            break;
                        default:
                            isMultiLine = false;
                            isNewLine = false;
                            if (!tmpdest.empty())
                            {
                                dest += tmpdest;
                                tmpdest.clear();
                            }
                            dest.push_back(c);
                        }
                        break;
                    }
                   case 1: {
						switch (c)
						{
						case '/':
							if (singleLine)
								state = 2;
							else
							{
								state = 0;
								if (!tmpdest.empty())
								{
									dest += tmpdest;
									tmpdest.clear();
								}
								dest.push_back(tmpc);
								dest.push_back(c);
							}
							break;
						case '*':
							if (multiLine)
								state = 3;
							else
							{
								state = 0;
								if (!tmpdest.empty())
								{
									dest += tmpdest;
									tmpdest.clear();
								}
								dest.push_back(tmpc);
								dest.push_back(c);
							}
							break;
						case ' ':
						case '\t':
							state = 0;
							isNewLine = false;
							isMultiLine = false;
							if (!tmpdest.empty())
							{
								dest += tmpdest;
								tmpdest.clear();
							}
							dest.push_back(tmpc);
							tmpdest.push_back(c);
							break;
						default:
							state = 0;
							isNewLine = (c == '\n' ? true : false);
							isMultiLine = false;
							if (!tmpdest.empty())
							{
								dest += tmpdest;
								tmpdest.clear();
							}
							dest.push_back(tmpc);
							dest.push_back(c);
						}
						break;
					}
					case 2: {
						switch (c)
						{
						case '\n':
							state = 0;
							if (!(isNewLine && singleRemove))
							{
								dest.push_back('\r');
								dest.push_back(c);
							}
							if (!tmpdest.empty())
								tmpdest.clear();
							isNewLine = true;
							break;
						}
						break;
					}
					case 3: {
						switch (c)
						{
						case '*':
							state = 4;
							break;
						case '\n':
							if (!multiRemove)
							{
								dest.push_back('\r');
								dest.push_back(c);
							}
						}
						break;
					}
					case 4: {
						switch (c)
						{
						case '/':
							state = 0;
							if (isNewLine)
								isMultiLine = true;
							break;
						default:
							state = 3;
						}
						break;
					}
					case 5: {
						switch (c)
						{
						case '"':
							state = 0;
							dest.push_back(c);
							break;
						default:
							dest.push_back(c);
						}
						break;
					}
					}
				}
			}
            else dest = src;
        }
    private:
        Comsedit() {};
    };

    bool Comsedit::singleLine = true;
    bool Comsedit::singleRemove = true;
    bool Comsedit::multiLine = true;
    bool Comsedit::multiRemove = true;
    bool Comsedit::emptyRemove = false;

