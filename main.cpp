#include "gmock/gmock.h"
#include "account.cpp"

using namespace testing;

class AccountTestFixture : public Test
{
public:
	Account account{ 10000, 0.05 };
};

TEST_F(AccountTestFixture, GetBalanceTest)
{
	EXPECT_EQ(account.getBalance(), 10000);
}

TEST_F(AccountTestFixture, DepositTest)
{
	account.deposit(1000);
	EXPECT_EQ(account.getBalance(), 11000);
}

TEST_F(AccountTestFixture, WithdrawTest)
{
	account.withdraw(4000);
	EXPECT_EQ(account.getBalance(), 6000);
}

TEST_F(AccountTestFixture, ApplyInterestTest)
{
	account.applyInterest();
	EXPECT_EQ(account.getBalance(), 10500);
}

TEST_F(AccountTestFixture, SetInterestTest)
{
	account.setInterest(0.1);
	account.applyInterest();
	EXPECT_EQ(account.getBalance(), 11000);
}

TEST_F(AccountTestFixture, GetExpectedBalanceTest)
{
	EXPECT_EQ(account.getExpectedBalance(1), 10500);
	EXPECT_EQ(account.getExpectedBalance(2), 11025);
	EXPECT_EQ(account.getExpectedBalance(3), 11576);
	EXPECT_EQ(account.getExpectedBalance(4), 12154);
	EXPECT_EQ(account.getExpectedBalance(5), 12761);
}

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}