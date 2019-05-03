class MastermindDigits {

public:
    MastermindDigits();
    MastermindDigits(unsigned int);
    ~MastermindDigits();
    MastermindDigits(const MastermindDigits&);

    void makeDigitsToGuess();
    unsigned int locationRight(const MastermindDigits) const;
    unsigned int locationWrong(const MastermindDigits)const;

    operator unsigned int() const;
    const MastermindDigits& operator=(const MastermindDigits&);

private:
    unsigned int* digits;
    size_t size;
};