#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
#include "Queue.h"
#include "Stack.h"

typedef List<std::string> StringLlist;
typedef List<int> IntLlist;
typedef List<double> DoubleLlist;

typedef Queue<int> IntQueue;
typedef Queue<std::string> StringQueue;
typedef Queue<double> DoubleQueue;

typedef Stack<int> IntStack;
typedef Stack<std::string> StringStack;
typedef Stack<double> DoubleStack;


#else

#include <list>
#include <stack>
#include <queue>

typedef std::list<std::string> StringLlist;
typedef std::list<int> IntLlist;
typedef std::list<double> DoubleLlist;

typedef std::queue<int> IntQueue;
typedef std::queue<std::string> StringQueue;
typedef std::queue<double> DoubleQueue;

typedef std::stack<int> IntStack;
typedef std::stack<std::string> StringStack;
typedef std::stack<double> DoubleStack;

#endif



void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}



int main()
{
	// TODO:
	// Write more tests to fully test your classes.

/* +++++++++++  StringLlist ++++++++++ */

	StringLlist BOB;
	BOB.push_front("A");
	Assert(BOB.front() == "A", "BOB Front == A");
	BOB.push_front("E");
	Assert(BOB.front() == "E", "BOB Front == E");
	BOB.push_front("D");
	Assert(BOB.front() == "D", "BOB Front == D");
	
	StringLlist SAM;
	SAM = BOB;

	Assert(SAM == BOB, "SAM == BOB");

	Assert(SAM.front() == "D", "SAM Front == D");
	SAM.pop_front();
	Assert(SAM.front() == "E", "SAM Front == E");
	SAM.pop_front();
	SAM.pop_front();
	Assert(SAM.empty() == true, "SAM is EMPTY");
	Assert(SAM.size() == 0, "SAM is size == 0");
	Assert(BOB.empty() == false, "BOB is Not EMPTY");
	Assert(BOB.size() == 3, "BOB is size == 3");
	
	Assert(SAM != BOB, "SAM != BOB");

/* +++++++++++  StringStack ++++++++++ */

	StringStack JAY{};
	JAY.push("A");
	Assert(JAY.top() == "A", "JAY Top == A");
	JAY.push("E");
	Assert(JAY.top() == "E", "JAY Top == E");
	JAY.push("D");
	Assert(JAY.top() == "D", "JAY Top == D");
	
	StringStack JACK{};
	JACK = JAY;

	Assert(JACK == JAY, "JACK == JAY");

	Assert(JACK.top() == "D", "JACK Top == D");
	JACK.pop();
	Assert(JACK.top() == "E", "JACK Top == E");
	JACK.pop();
	JACK.pop();
	Assert(JACK.empty() == true, "JACK is EMPTY");
	Assert(JACK.size() == 0, "JACK size is 0");
	Assert(JAY.empty() == false, "JAY is Not EMPTY");
	Assert(JAY.size() == 3, "JAY size is 3");
	
	Assert(JACK != JAY, "JACK != JAY");

/* +++++++++++ StringQueue ++++++++++ */

	StringQueue HELO;
	HELO.push("A");
	Assert(HELO.front() == "A", "HELLO Front == A");
	HELO.push("E");
	Assert(HELO.back() == "E", "HELLO Front == E");
	HELO.push("D");
	Assert(HELO.back() == "D", "HELLO Front == D");
	
	StringQueue ROBERT;
	ROBERT = HELO;

	Assert( ROBERT == HELO, "ROBERT == HELO");

	Assert(ROBERT.front() == "A", "ROBERT Front== A");
	ROBERT.pop();
	Assert(ROBERT.front() == "E", "ROBERT Front == E");
	Assert(ROBERT.back() == "D", "ROBERT Back == D");
	ROBERT.pop();
	ROBERT.pop();
	Assert(ROBERT.empty() == true, "ROBERT is EMPTY");
	Assert(ROBERT.size() == 0, "ROBERT size is 0");
	Assert(HELO.empty() == false, "HELO is Not EMPTY");
	Assert(HELO.size() == 3, "HELO size is 3");
	
	Assert( ROBERT != HELO, "ROBERT != HELO");

/* +++++++++++ DoubleLlist ++++++++++ */

	DoubleLlist ALAN;
	ALAN.push_back(8.5);
	ALAN.push_back(9.5);
	ALAN.push_back(9.5);
	ALAN.push_back(2.5);
	ALAN.push_back(7.5);
	ALAN.push_back(4.5);
	Assert(ALAN.back() == 4.5, "ALAN back is 4.5");
	ALAN.pop_back();
	Assert(ALAN.back() == 7.5, "ALAN back is 7.5");
	ALAN.pop_back();
	Assert(ALAN.back() == 2.5, "ALAN back is 2.5");

	DoubleLlist WALKER;
	WALKER = ALAN;

	Assert(WALKER == ALAN, "WALKER == ALAN");

	ALAN.pop_back();
	ALAN.pop_back();
	ALAN.pop_back();
	ALAN.pop_back();
	Assert(ALAN.empty() == true, "ALAN is EMPTY");
	Assert(ALAN.size() == 0, "WALKER size is 0");
	Assert(WALKER.empty() == false, "WALKER is not EMPTY");
	Assert(WALKER.size() == 4, "WALKER size is 4");

/* +++++++++++ DoubleStack ++++++++++ */
	
	DoubleStack STEVE{};
	STEVE.push(8.5);
	STEVE.push(9.5);
	STEVE.push(9.5);
	STEVE.push(2.5);
	STEVE.push(7.5);
	STEVE.push(4.5);
	Assert(STEVE.top() == 4.5, "STEVE top is 4.5");
	STEVE.pop();
	Assert(STEVE.top() == 7.5, "STEVE top is 7.5");
	STEVE.pop();
	Assert(STEVE.top() == 2.5, "STEVE top is 2.5");

	DoubleStack ROB{};
	ROB = STEVE;

	Assert(ROB == STEVE, "ROB == STEVE");

	STEVE.pop();
	STEVE.pop();
	STEVE.pop();
	STEVE.pop();
	Assert(STEVE.empty() == true, "STEVE is EMPTY");
	Assert(STEVE.size() == 0, "STEVE size is 0");
	Assert(ROB.empty()  ==  false, "ROB is not EMPTY");
	Assert(ROB.size() == 4, "BOB size is 4");
	
	Assert(ROB != STEVE, "ROB != STEVE");

/* +++++++++++ DoubleQueue ++++++++++ */
	
	DoubleQueue XAVI;
	XAVI.push(8.5);
	XAVI.push(9.5);
	XAVI.push(5.5);
	XAVI.push(2.5);
	XAVI.push(7.5);
	XAVI.push(4.5);
	Assert(XAVI.front() == 8.5, "XAVI front is 8.5");
	XAVI.pop();
	Assert(XAVI.front() == 9.5, "XAVI front is 9.5");
	XAVI.pop();
	Assert(XAVI.front() == 5.5, "XAVI front is 5.5");
	Assert(XAVI.back()  == 4.5, "XAVI back is 4.5");

	DoubleQueue TANK;
	TANK = XAVI;

	Assert(TANK == XAVI, "TANK == XAVI");	

	XAVI.pop();
	XAVI.pop();
	XAVI.pop();
	XAVI.pop();
	Assert(XAVI.empty() == true, "XAVI is EMPTY");
	Assert(XAVI.size() == 0, "XAVI size is 0");
	Assert(TANK.empty() == false, "TANK is not EMPTY");
	Assert(TANK.size() == 4, "TANK size is 4");
	
	Assert(TANK != XAVI, "TANK != XAVI");	

/* +++++++++++ IntLlist ++++++++++ */

	IntLlist OWL;
	OWL.push_back(85);
	OWL.push_back(95);
	OWL.push_back(95);
	OWL.push_back(25);
	OWL.push_back(75);
	OWL.push_back(45);
	Assert(OWL.back() == 45, "OWL back is 45");
	OWL.pop_back();
	Assert(OWL.back() == 75, "OWL back is 75");
	OWL.pop_back();
	Assert(OWL.back() == 25, "OWL back is 25");

	IntLlist BRIAN;
	BRIAN = OWL;

	Assert(BRIAN == OWL, "BRIAN == OWL");

	OWL.pop_back();
	OWL.pop_back();
	OWL.pop_back();
	OWL.pop_back();
	Assert(OWL.empty() == true, "OWL is EMPTY");
	Assert(OWL.size() == 0, "OWL size is 0");
	Assert(BRIAN.empty() == false, "BRIAN is not EMPTY");
	Assert(BRIAN.size() == 4, "BRIAN size is 4");
	
	Assert(BRIAN != OWL, "BRIAN != OWL");

/* +++++++++++ IntStack ++++++++++ */

	IntStack VIM{};
	VIM.push(85);
	VIM.push(95);
	VIM.push(95);
	VIM.push(25);
	VIM.push(75);
	VIM.push(45);
	Assert(VIM.top() == 45, "VIM top is 45");
	VIM.pop();
	Assert(VIM.top() == 75, "VIM top is 75");
	VIM.pop();
	Assert(VIM.top() == 25, "VIM top is 25");

	IntStack RODOLFO{};
	RODOLFO = VIM;

	Assert(RODOLFO == VIM, "RODOLFO == VIM");

	VIM.pop();
	VIM.pop();
	VIM.pop();
	VIM.pop();
	Assert(VIM.empty() == true, "VIM is EMPTY");
	Assert(VIM.size() == 0, "RODOLFO size is 0");
	Assert(RODOLFO.empty() == false, "RODOLFO is not EMPTY");
	Assert(RODOLFO.size() == 4, "RODOLFO size is 4");
	
	Assert(RODOLFO != VIM, "RODOLFO != VIM");

/* +++++++++++ IntQueue ++++++++++ */
	
	IntQueue LIAN;
	LIAN.push(85);
	LIAN.push(95);
	LIAN.push(55);
	LIAN.push(25);
	LIAN.push(75);
	LIAN.push(45);
	Assert(LIAN.front() == 85, "LIAN front is 85");
	LIAN.pop();
	Assert(LIAN.front() == 95, "LIAN front is 95");
	LIAN.pop();
	Assert(LIAN.front() == 55, "LIAN front is 55");
	Assert(LIAN.back() == 45, "LIAN back is 45");

	IntQueue URCI;
	URCI = LIAN;

	Assert(URCI == LIAN, "URCI == LIAN");

	LIAN.pop();
	LIAN.pop();
	LIAN.pop();
	LIAN.pop();
	Assert(LIAN.empty() == true, "LIAN is EMPTY");
	Assert(LIAN.size() == 0, "LIAN size is 0");
	Assert(URCI.empty() == false, "URCI is not EMPTY");
	Assert(URCI.size() == 4, "URCI size is 4");
	
	Assert(URCI != LIAN, "URCI != LIAN");

	return 0;
}


