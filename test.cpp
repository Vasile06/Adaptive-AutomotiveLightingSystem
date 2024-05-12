#include "pch.h" //accelerarea compilarii
#include "Integration_test_fixture.h"

               // Unit Tests


TEST(BUTTONUNITTEST, GIVENVALUE_EXPECTEDSAMEVALUE) {
	//VERIFICAM DACA STAREA ESTE SETATA SI DACA ESTE OBTINUTA CORECT PENTRU .. STARI
	Button BT{};

	BT.SetState({ ButtonState::Off });
	EXPECT_EQ(BT.GetState(), ButtonState::Off);

	BT.SetState({ ButtonState::LowBeam });
	EXPECT_EQ(BT.GetState(), ButtonState::LowBeam);

	BT.SetState({ ButtonState::HighBeam });
	EXPECT_EQ(BT.GetState(), ButtonState::HighBeam);

	BT.SetState({ ButtonState::Automatic });
	EXPECT_EQ(BT.GetState(), ButtonState::Automatic);
}



             //Integration Tests



TEST_F(BeamsTestFixture, GivenAutomaticAndDark_WhenVehicleApproching_ExpectSwitchLowBeam)
{
	SetUp();
	CalculateLightsState();

	EXPECT_EQ(std::get<0>(GetMLResult()), DisplayState::Blue);
	EXPECT_EQ(std::get<1>(GetMLResult()), LightsState::HighBeamLED);

	Manager_Actuators m_a = Manager_Actuators(GetML());

	m_a.SetDisplay();
	m_a.SetLights();

	EXPECT_EQ(m_a.GetDisplay().GetLedColor(), DisplayState::Blue);
	EXPECT_EQ(m_a.GetLights().GetLights(), LightsState::HighBeamLED);

	SetSensorProximity(30.0); // vehicle approching

	CalculateLightsState();

	EXPECT_EQ(std::get<0>(GetMLResult()), DisplayState::Green);
	EXPECT_EQ(std::get<1>(GetMLResult()), LightsState::LowBeamLED);

	m_a.ReadManagerLights(GetML());
	m_a.SetDisplay();
	m_a.SetLights();

	EXPECT_EQ(m_a.GetDisplay().GetLedColor(), DisplayState::Green);
	EXPECT_EQ(m_a.GetLights().GetLights(), LightsState::LowBeamLED);
}
TEST_F(BeamsTestFixture, GivenNothing_ExpectNothing)
{

	Manager_Actuators m_a = Manager_Actuators(GetML());

	m_a.SetDisplay();
	m_a.SetLights();

	EXPECT_EQ(m_a.GetDisplay().GetLedColor(), DisplayState::Blue);
	EXPECT_EQ(m_a.GetLights().GetLights(), LightsState::HighBeamLED);
}








//// A simple function that causes a division by zero error
//int Divide(int a, int b) {
//	return a / b;
//}
//
//// A death test to check that calling Divide with b = 0 results in program termination
//TEST(DeathTest, DivideByZero) {
//	EXPECT_DEATH(Divide(10, 0), "");
//}
//
//// Function to dereference a pointer and throw an exception if it is null
//int dereferencePointer(int* ptr) {
//	//if (ptr == nullptr) {
//	//throw std::invalid_argument("Null pointer dereferenced.");
//	//}
//	return *ptr;
//}
//
//// Death test to check if the function correctly throws an exception for null pointers
//TEST(DereferencePointerDeathTest, NullPointerTest) {
//	int* nullPointer = nullptr;
//	ASSERT_DEATH(dereferencePointer(nullPointer), "");
//}
//TEST(TransposeMatrixTest, BasicTest) {
//
//
//	// Original matrix
//	std::vector<std::vector<float>> original = {
//		  {1, 2, 3},
//		  {4, 5, 6},
//		  {7, 8, 9}
//	};
//
//	// Expected transpose
//	std::vector<std::vector<float>> expectedTranspose = {
//		  {1, 4, 7},
//		  {2, 5, 8},
//		  {3, 6, 9}
//	};
//
//	Filters filter;
//
//	std::vector<std::vector<float>> emptyMatrix;
//	// here we assert an invalid_argument to be throwen, if not, the tests stops
//	ASSERT_THROW(filter.transposeMatrix(emptyMatrix), std::invalid_argument);
//
//	// Compute transpose
//	auto result = filter.transposeMatrix(original);
//
//	// Verify the result
//	ASSERT_EQ(result.size(), expectedTranspose.size());
//
//	for (size_t i = 0; i < result.size(); ++i) {
//		ASSERT_EQ(result[i].size(), expectedTranspose[i].size());
//	}
//
//	EXPECT_EQ(result, expectedTranspose);// si pe containers
//}


 




