#pragma once

class Account
{
public:
	Account(int balance, double interest) : balance{ balance }, interest { interest }
	{
	}

	int getBalance()
	{
		return balance;
	}

	void deposit(int money)
	{
		balance += money;
	}

	void withdraw(int money)
	{
		balance -= money;
	}

	void applyInterest()
	{
		balance = static_cast<int>(balance * (1 + interest));
	}

	void setInterest(double interest)
	{
		this->interest = interest;
	}

	int getExpectedBalance(int year)
	{
		int result = balance;
		while (year > 0)
		{
			result = static_cast<int>(result * (1 + interest));
			year--;
		}

		return result;
	}

private:
	int balance;
	double interest;
};