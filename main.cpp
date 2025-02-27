#include "pch.h"
#include <ReverseMode.h>
#include <Logging.h>
#include <FeedForward.h>
#include <Vector.h>
#include <arrayfire.h>

int main(){	

	latern::Node b1(1.0,"b1");
	latern::Node b2(2.0,"b2");
	latern::Node b3(3.0,"b3");
	latern::Node b4 = b1 + b2;
	latern::Node b5 = b3 + b4;
	b4.SetLabel("b4");
	b5.SetLabel("b5");
	std::cout << std::string(50,'=') << "\n";
	latern::print(b5);
	latern::print(b4);
	latern::print(b3);
	latern::print(b2);
	latern::print(b1);
	std::cout << std::string(50,'=') << "\n";
	
	b1.value = 2.0;
	latern::utility::Vector<latern::Node*> fix_position_node;
	latern::FeedForward(&b5,fix_position_node);

	std::cout << std::string(50,'=') << "\n";
	latern::print(b5);
	latern::print(b4);
	latern::print(b3);
	latern::print(b2);
	latern::print(b1);
	std::cout << std::string(50,'=') << "\n";

	latern::Node c1(2.5,"c1");
	latern::Node c2(3.4,"c2");
	latern::Node c3 = c1 * c2;
	latern::Node c4 = c1 + c2;
	latern::Node c5 = c3 / c4;
	latern::Node c6 = c1 * c5;
	c3.SetLabel("c3");
	c4.SetLabel("c4");
	c5.SetLabel("c5");
	c6.SetLabel("c6");
	latern::ReverseModeAD(c6);
	
	// std::cout << std::string(50,'=') << "\n";
	// print(c6);
	// print(c5);
	// print(c4);
	// print(c3);
	// print(c2);
	// print(c1);
	// std::cout << std::string(50,'=');

	// Node a1(4.4,"a1");
	// Node a2(3.3,"a2");
	// Node a3 = Sigmoid(a1);
	// Node a4 = Sigmoid(a2);
	// Node a5 = NaturalLog(a4);
	// Node a6 = a4 * a5;
	// Node a7 = a3 * a6;
	// a3.SetLabel("a3");
	// a4.SetLabel("a4");
	// a5.SetLabel("a5");
	// a6.SetLabel("a6");
	// a7.SetLabel("a7");
	// ReverseModeAD(a7);

	// std::cout << std::string(50,'=') << "\n";
	// print(a7);
	// print(a6);
	// print(a5);
	// print(a4);
	// print(a3);
	// print(a2);
	// print(a1);
	// std::cout << std::string(50,'=');

    // Node x(2.5);
    // Node sg = Sigmoid(x);
    // Node sg2 = Sigmoid(sg);

    // ReverseModeAD(sg2);
	// std::cout << std::string(30,'=') << "\n";
	// print(sg2,"Sigmoid 2");
	// print(sg,"Sigmoid 1");
	// print(x,"x");
	// std::cout << std::string(30,'=') << "\n\n";

    // Node a(2.0);
	// Node b(3.0);
	// Node c(4.0);
	// Node x1 = a + b;
	// Node x2 = x1 * c;
	
	// ReverseModeAD(x2);
	// std::cout << std::string(30,'=') << "\n";
	// print(x2,"x2");
	// print(x1,"x1");
	// print(a,"a");
	// print(b,"b");
	// print(c,"c");
	// std::cout << std::string(30,'=') << "\n\n";
	
    return EXIT_SUCCESS;
}