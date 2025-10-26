class Bank {
public:
    vector<long long> balance;
    int n;

    Bank(vector<long long>& balance) {
        n = balance.size();
        this->balance = balance;
    }

    bool transfer(int acc1, int acc2, long long money) {
        if (acc1 > n || acc2 > n || balance[acc1 - 1] < money) 
            return false;

        balance[acc1 - 1] -= money;
        balance[acc2 - 1] += money;
        return true;
    }

    bool deposit(int acc, long long money) {
        if (acc > n)
            return false;

        balance[acc - 1] += money;
        return true;
    }

    bool withdraw(int acc, long long money) {
        if (acc > n || balance[acc - 1] < money)
            return false;

        balance[acc - 1] -= money;
        return true;
    }
};
