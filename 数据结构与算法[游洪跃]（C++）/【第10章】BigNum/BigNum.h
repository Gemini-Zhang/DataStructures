#ifndef __LARGEINT_H__
#define __LARGEINT_H__

#include "LinkList.h"

/// �Ǹ���������
class BigNum
{
protected:
///  �Ǹ�������������ݳ�Ա:
	DblLinkList<unsigned int> num;					// �洢�Ǹ�������ֵ

/// ��������
	BigNum Multi10Power(unsigned int exponent) const;// ��10�Ľ���10^exponent
	BigNum operator *(unsigned int digit) const;	// �˷����������(����1λ��)
	void TrimLeftZero();							// ȥ���Ǹ�����������0

public:
///  �������������ر���ϵͳĬ�Ϸ�������:
	BigNum(unsigned int n);						// ���캯��
	BigNum &operator =(const BigNum &copy);	// ��ֵ���������
	friend BigNum operator +(const BigNum &a, const BigNum &b);	// �ӷ������+����
	friend BigNum operator *(const BigNum &a, const BigNum &b);	// �˷������*����
	friend bool operator <(const BigNum &a, const BigNum &b);			// ��ϵ�����<����
	friend ostream &operator <<(ostream &outStream, const BigNum &outLargeInt); // ���������<<
	friend BigNum Power(const BigNum &base,	const BigNum &exp);

};

/// �Ǹ����������ʵ�ֲ���
// �������: ����ֵΪnum�ķǸ��������������캯��
BigNum::BigNum(unsigned int num)
{
	int r, q;					// r������q��

	q = num;
	while (q != 0)
	{	//��lNum�ĸ�λ
		r = q % 10;				// rΪq�ĵ�ǰ��λ��
		this->num.Insert(1, r);	// ���뵽˫��������
		q = q / 10;				// ��һ�����λ
	}
}

void BigNum::TrimLeftZero()
// ���������ȥ��������0
{
	unsigned int digit;							// ��ǰ�Ǹ���������һλ
	for (num.GetElem(1, digit); digit == 0; num.GetElem(1, digit));	// ȥ��������0
}

BigNum &BigNum::operator =(const BigNum &copy)
// ������������Ǹ�������copy��ֵ����ǰ�Ǹ�������������ֵ�������
{
	if (&copy != this)
	{
		this->num = copy.num;			// num���ڴ洢�Ǹ�������
	}

	return *this;
}

// ����������ӷ������+����
BigNum operator +(const BigNum &a, const BigNum &b)
{
	BigNum bigNum(0);
	unsigned int carry = 0;				// ��λ
	unsigned int digit1, digit2;		// ��ʾ�Ǹ��������ĸ�λ
	unsigned int pos1, pos2;			// ��ʾ�Ǹ��������ĸ�λ��λ��

	pos1 = a.num.Length();				// ������a�ĸ�λλ��
	pos2 = b.num.Length();				// ����b�ĸ�λλ��
	while (pos1 > 0 && pos2 > 0)
	{	// �Ӹ�λ��ʼ���
		a.num.GetElem(pos1--, digit1);	// ��������һλ
		b.num.GetElem(pos2--, digit2);	// ������һλ
		bigNum.num.Insert(1, (digit1 + digit2 + carry) % 10);	// ����͵��µ�һλ
		carry = (digit1 + digit2 + carry) / 10;	// �µĽ�λ
	}

	while (pos1 > 0)
	{	// ����������λû�����
		a.num.GetElem(pos1--, digit1);	// a��һλ
		bigNum.num.Insert(1, (digit1 + carry) % 10);		// ����͵��µ�һλ
		carry = (digit1 + carry) / 10;	// �µĽ�λ
	}

	while (pos2 > 0)
	{	// ��������λû�����
		b.num.GetElem(pos2--, digit2);	// ������һλ
		bigNum.num.Insert(1, (digit2 + carry) % 10);		// ����͵��µ�һλ
		carry = (digit2 + carry) / 10;			// �µĽ�λ
	}

	if (carry > 0)
	{	// ���ڽ�λ
		bigNum.num.Insert(1, carry);		// ���λ��λ
	}

	return bigNum;
}

// ����������˷������*����
BigNum operator *(const BigNum &a, const BigNum &b)
{
	BigNum bigNum(0);
	unsigned int digit;							// ��ʾһλ����
	unsigned int len = b.num.Length();			// ����λ��

	for (int pos = len; pos > 0; pos--)
	{	// �ó���b��ÿһλ�뱻����a���
		b.num.GetElem(pos, digit);				// ȡ��������һλ
		bigNum = bigNum + a.Multi10Power(len - pos) * digit;
			// �ۼӳ���b��ÿһλ�뱻����a�ĳ˻�
	}

	return bigNum;
}

// �����������10�Ľ���
BigNum BigNum::Multi10Power(unsigned int exponent) const
{
	BigNum bigNum = *this;;

	for (unsigned int i = 0; i < exponent; i++)
	{	// ��exponentλΪ0
		bigNum.num.Insert(bigNum.num.Length() + 1, 0);
	}
	return bigNum;
}

// ����������˷����������(����һλ��)
BigNum BigNum::operator *(unsigned int digit) const
{
	BigNum bigNum(0);
	unsigned int carry = 0;					// ��λ
	unsigned int tmpDigit;					// ��ǰ�Ǹ���������ĳλ
	for (int pos = this->num.Length(); pos > 0; pos--)
	{	// ��digit���γ˵�ǰ�Ǹ��������ĸ�λ
		this->num.GetElem(pos, tmpDigit);	// ȡ��һλ
		bigNum.num.Insert(1, (tmpDigit * digit + carry) % 10);	// tmpDigit * digit��һλ
		carry = (tmpDigit * digit + carry) / 10;	// tmpDigit * digit�Ľ�λ
	}

	if (carry > 0)
	{	// ���ڽ�λ
		bigNum.num.Insert(1, carry);
	}

	return bigNum;
}


// �����������ϵ�����<����
bool operator <(const BigNum &a, const BigNum &b)
{
	BigNum first = a, second = b;		// �ݴ�a��b, �Ա���д���
	first.TrimLeftZero();	second.TrimLeftZero();		// ȥ��������0
	int len1 = first.num.Length(), len2 = second.num.Length();	// first(a)��second(b)��λ��
	if (len1 < len2) return true;			// first(a)λ����С
	else if (len1 > len2) return false;		// first(a)λ������
	else
	{	// first(a)��second(b)��λ�����
		for (int pos = 1; pos <= len1; pos++)
		{	// �Ӹ�λ����λ���αȽ�first(a)��second(b)�ĸ�λ
			unsigned int digit1, digit2;			// ��ʾ�Ǹ��������ĸ�λ
			first.num.GetElem(pos, digit1);			// first(a)��1λ
			second.num.GetElem(pos, digit2);		// second(b)��1λ
			if (digit1 < digit2) return true;		// first(a)��С
			else if  (digit1 > digit2) return false;// first(a)����
		}
	}
	return false;									// ��ʱfirst(a)��second(b)�ĸ�λ���
}

// ���������<<
ostream &operator <<(ostream &outStream, const BigNum &outLargeInt)
{
	int len = outLargeInt.num.Length();				// outLargeIntλ��
	if (len == 0)
	{	// outLargeIntΪ0
		cout << 0;									// ���0
	}
	else
	{	// outLargeInt��0
		for (int pos = 1; pos <= outLargeInt.num.Length(); pos++)
		{	// ���������λ
			unsigned int digit;						// �Ǹ���������ĳλ
			outLargeInt.num.GetElem(pos, digit);	// ȡ��һλ
			outStream << digit;						// ��ʾһλ
		}
	}

	return outStream;
}


// �ļ�·����:power\power.h
BigNum Power(const BigNum &base,	const BigNum &exp)
// �������: �����Ǹ��������Ĵ�Ǹ��������η�
{
	BigNum tmpLargInt(1);
	for (int i = 0; i < exp; i = i + 1)
	{	// �������Ǹ��������Ĵ�Ǹ��������η�
		tmpLargInt = tmpLargInt * base;
	}

	return tmpLargInt;
}


#endif
