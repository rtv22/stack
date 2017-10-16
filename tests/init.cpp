#include <stack.hpp>
#include <catch.hpp>

SCENARIO("init", "[init]") {
	stack<int> A;
	REQUIRE(array_size_() == 0);
	REQUIRE(count_() == 0);
}

SCENARIO("Push", "[push]") {
	stack<int> A;
	A.push(1);
	A.push(2);
	REQUIRE(A.count_() == 2));
}

SCENARIO("Pop", "[pop]") {
	stack<int> A;
	A.push(1);
	A.push(2);
	A.pop();
	REQUIRE(A.count_() == 1));
}

SCENARIO("oper=", "[oper=]"){
	stack<int> A;
	A.push(1);
	A.push(2);
	stack<int> B;
	B = A;
	REQUIRE(B.count_() == 2));
}
