#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>

class Person {
protected:
    char *name;
    int age;
public:
    Person(char *name, int age);
    char *getName();
    int getAge();
};

class Peasant : public Person {
private:
    Person *benefactor;
public:
    Peasant(char *name, int age, Person *benefactor);
    Person *getBenefactor();
    void printBenefactorInfo();
};

class Knight : public Person {
private:
    char *order, *steed;
public:
    Knight(char *name, int age, char *order, char *steed);
    void printOrderInfo();
    void printSteedInfo();
};

Person::Person(char *name, int age)
{
    this->name = name;
    this->age = age;
}

char *Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

Peasant::Peasant(char *name, int age, Person *benefactor) : Person(name, age)
{
    this->name = name;
    this->age = age;
    this->benefactor = benefactor;
}

Person *Peasant::getBenefactor()
{
    return benefactor;
}

void Peasant::printBenefactorInfo()
{
    std::cout << "So be it known that " << benefactor->getName()
              << ", of " << benefactor->getAge() << " years, "
              << "sponsors " << name << " before none or all." << std::endl;
}

Knight::Knight(char *name, int age, char *order, char *steed) : Person(name, age)
{
    this->name = name;
    this->age = age;
    this->order = order;
    this->steed = steed;
}

void Knight::printOrderInfo()
{
    std::cout << "Verily, the order of good " << name << " "
              << "is that of the " << order << "." << std::endl;
}

void Knight::printSteedInfo()
{
    std::cout << "And hark, ne'er-do-wells, for " << name << " "
              << "commands the noble steed " << steed << "!" << std::endl;
}

void moveOnToNextInput()
{
    std::cin.clear();
    while (!std::cin.eof() && std::cin.get() != '\n') ;
}

int main()
{
    /* easily tweakable */
    const size_t SZ = BUFSIZ, INPUT_INDENT = 4;
    const char *INDENT_PROMPTER = "> ", YES = 'y', NO = 'n';
    const int BABY_AGE_MAX = 4, OLD_AGE_MIN = 50,
              RIDICULOUS_AGE = 120,
              GOOD_ADVENTURING_AGE = 16,
              PT_BENEF_AGE_MIN = 15,
              PT_BENEF_AGE_MAX = 60;

    char inName[SZ], inOrder[SZ], inSteed[SZ], ptName[SZ],
         ptHasBenefAns, ptBenefName[SZ], careAbtBenefAgeAns,
         *inAgeComment;
    int inAge, ptAge, ptBenefAge;
    bool errorFlag = false,
         ptHasBenefBln = false, careAbtBenefAgeBln = false;

    std::srand(std::time(0));

    std::cout << "May you walk under calm skies, traveler. Give thy name." << std::endl
              << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
    std::cin.getline(inName, SZ);

    do {
        if (!errorFlag)
        {
            std::cout << "Forsooth, an elegant name dresses thee. How many years compose thine age?" << std::endl;
        }
        else
        {
            moveOnToNextInput();
            std::cout << "Thou speakest in riddles. A number of reason is asked of you." << std::endl;
        }
        std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER;
        std::cin  >> inAge;
    } while (errorFlag = std::cin.fail() || inAge <= 0);
    moveOnToNextInput();

    if (inAge <= BABY_AGE_MAX) inAgeComment = (char*)"By the gods, thou art a mere baby!";
    else if (inAge < GOOD_ADVENTURING_AGE) inAgeComment = (char*)"Thou art a small one.";
    else if (inAge > RIDICULOUS_AGE) inAgeComment = (char*)"Thou art surely undead and a lich's thrall.";
    else if (inAge >= OLD_AGE_MIN) inAgeComment = (char*)"To exert yourself so at such an age!";
    else inAgeComment = (char*)"The ancient stars would champion such youth.";

    std::cout << inAgeComment << " From what order dost thou hail?" << std::endl
              << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
    std::cin.getline(inOrder, SZ);

    do {
        if (!errorFlag)
        {
            std::cout << "May it stand as a beacon evermore! Finally, what is the name of thy battle-horse?" << std::endl;
        }
        else
        {
            std::cout << "Poppycock. An owner and his horse are not to be named the same. What is the true name?" << std::endl;
        }
        std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
        std::cin.getline(inSteed, SZ);
    } while (errorFlag = (std::strncmp(inName, inSteed, SZ) == 0));

    std::cout << std::endl;

    Knight k(inName, inAge, inOrder, inSteed);
    k.printOrderInfo();
    k.printSteedInfo();
    std::cout << std::endl;

    do {
        if (!errorFlag)
        {
            std::cout << "Now 'tis a curious truth that upon thy travels, thou hast oft seen the same peasant," << std::endl
                      << "who sported either bravery or foolishness toward the peril that might have been at hand." << std::endl
                      << "What is the name of this peasant?" << std::endl;
        }
        else
        {
            std::cout << "Thou art certainly not the peasant. 'Tis the suggestion to give a different name." << std::endl;
        }
        std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
        std::cin.getline(ptName, SZ);
    } while (errorFlag = (std::strncmp(ptName, inName, SZ) == 0));

    do {
        if (!errorFlag)
        {
            std::cout << "And over how many years has " << ptName << " been in the realm of the living?" << std::endl;
        }
        else
        {
            moveOnToNextInput();
            std::cout << "Humor is quite good, but to give a number of value is thy prize here." << std::endl;
        }
        std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
        std::cin  >> ptAge;
    } while (errorFlag = std::cin.fail() || ptAge <= 0);
    moveOnToNextInput();

    do {
        if (!errorFlag)
        {
            std::cout << "Haveth the unfortunate one a benefactor? Yea or nay?" << std::endl;
        }
        else
        {
            moveOnToNextInput();
            std::cout << "Hold thy tongue, and do adjust it. Thou art to answer yea or nay." << std::endl;
        }
        std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
        std::cin  >> ptHasBenefAns;
    } while (errorFlag = (std::tolower(ptHasBenefAns) != YES &&
                          std::tolower(ptHasBenefAns) != NO));
    moveOnToNextInput();

    if (ptHasBenefBln = (std::tolower(ptHasBenefAns) == YES))
    {
        do {
            if (!errorFlag)
            {
                std::cout << "What is the name of this gracious benefactor?" << std::endl;
            }
            else
            {
                std::cout << "A jest! Thou art too occupied by thy ventures. Thou willst give another name." << std::endl;
            }
            std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
            std::cin.getline(ptBenefName, SZ);
        } while (errorFlag = (std::strncmp(ptBenefName, inName, SZ) == 0));

        do {
            if (!errorFlag)
            {
                std::cout << "Knowest or carest thou of that good person's age? Yea or nay?" << std::endl;
            }
            else
            {
                moveOnToNextInput();
                std::cout << "A free spirit dwells within thee, but \"yea\" or \"nay\" shall suffice." << std::endl;
            }
            std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
            std::cin  >> careAbtBenefAgeAns;
        } while (errorFlag = (std::tolower(careAbtBenefAgeAns) != YES &&
                              std::tolower(careAbtBenefAgeAns) != NO));
        moveOnToNextInput();

        if (careAbtBenefAgeBln = (std::tolower(careAbtBenefAgeAns) == YES))
        {
            do {
                if (!errorFlag)
                {
                    std::cout << "And over how many years has that soul been of this world?" << std::endl;
                }
                else
                {
                    moveOnToNextInput();
                    std::cout << "Good sojourner, a number of sense is the request." << std::endl;
                }
                std::cout << std::setw(INPUT_INDENT) << INDENT_PROMPTER << std::setw(0);
                std::cin  >> ptBenefAge;
            } while (errorFlag = std::cin.fail() || ptBenefAge <= 0);
        }
    }
    else std::cout << "In that case, may grace befall such a one!" << std::endl;

    Person *bn = 0;
    if (ptHasBenefBln)
    {
        if (!careAbtBenefAgeBln) ptBenefAge = PT_BENEF_AGE_MIN +
            (std::rand() / (RAND_MAX / PT_BENEF_AGE_MAX));
        bn = new Person(ptBenefName, ptBenefAge);
    }
    Peasant pt(ptName, ptAge, bn);
    if ((Person*)bn)
    {
        std::cout << std::endl;
        pt.printBenefactorInfo();
        delete bn;
    }

    std::cout << std::endl
              << "Gratitude and fortune to thee, traveler. No more is asked of you." << std::endl
              << "Brandish thine equipment with pride, and may the deities of goodness" << std::endl
              << "deem thee as their champion." << std::endl;

    return 0;
}
