//a program that determines if a square is magic or not
							//make a magic square -> 1)ODD	2)SINGLY EVEN	3)DOUBLY EVEN


#include <iostream>
#include <vector>


using namespace std;

bool IsMagic()
{
	int n;
	int sum = 0;
	int sum2 = 0;
	bool flag = 1;

	cout << "enter n" << endl;
	cin >> n;
	//vector<vector<int>>ptr(n, vector<int>(n));

	int **ptr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ptr[i] = new int[n];
	}

	cout << "enter the values in the table from right to left and up to down" << endl;
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n;j++)
			cin >> ptr[i][j];
	}

	for (int k = 0;k < n;k++)		//checking first row
		sum += ptr[0][k];

	for (int i = 1;i < n;i++)		//checking every row
	{
		for (int j = 0;j < n;j++)
		{
			sum2 += ptr[i][j];
		}
		if (sum == sum2)
			sum2 = 0;
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag==1)		//cheking columns
	{ 
		for (int i = 1;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				sum2 += ptr[j][i];
			}
			if (sum == sum2)
				sum2 = 0;
			else
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag == 1)		//checking main diameter
	{
		for (int i = 0;i < n;i++)
			sum2 += ptr[i][i];
	}
	if (sum2 == sum)
		sum2 = 0;
	else
		flag = 0;
	if (flag == 1)		//checking sub diameter
	{
		int j = n - 1;
		for (int i = 0 ;i < n;i++, j--)
			sum2 += ptr[i][j];
	}
	if (sum2 != sum)
		flag = 0;
	for (int i = 0;i < n;i++)
		delete[]ptr[i];
	delete[]ptr;
	if (flag == 0)
		return false;
	if (flag == 1)
		return true;
}


void printMatrix(vector< vector<int> > &matrix,int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void DoublyEven(int n)
{
	vector<vector<int>>arr(n, vector<int>(n));
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)	// filling array with its count value 
			arr[i][j] = (n*i) + j + 1;
	}

	for (int i = 0; i<n / 4; i++)		// Top Left corner of Matrix 
	{
		for (int j = 0; j<n / 4; j++)
			arr[i][j] = (n*n + 1) - arr[i][j];
	}

	for (int i = 0; i< n / 4; i++)		// Top Right corner of Matrix 
	{
		for (int j = 3 * (n / 4); j<n; j++)
			arr[i][j] = (n*n + 1) - arr[i][j];
	}
	
	for (int i = 3 * n / 4; i<n; i++)		// Bottom Left corner of Matrix 
	{
		for (int j = 0; j<n / 4; j++)
			arr[i][j] = (n*n + 1) - arr[i][j];
	}
	
	for (int i = 3 * n / 4; i<n; i++)		// Bottom Right corner of Matrix 
	{
		for (int j = 3 * n / 4; j<n; j++)
			arr[i][j] = (n*n + 1) - arr[i][j];
	}

	for (int i = n / 4; i<3 * n / 4; i++)		// Centre of Matrix
	{
		for (int j = n / 4; j<3 * n / 4; j++)
			arr[i][j] = (n*n + 1) - arr[i][j];
	}

	printMatrix(arr, n);
	return;
}


void SinglyEven(int n)
{
	vector<vector<int>>matrix(n, vector<int>(n));
	int p = n / 2;
	vector<vector<int> > M(p, vector<int>(p, 0));
	int k = 1;
	int i = 0;
	int j = p / 2;
	int numofelm = p*p;

	for (int k = 1;k <= numofelm;k++)
	{
		M[i][j] = k;
		i--;
		j++;
		if (k%p == 0)
		{
			i += 2;
			j--;
		}
		if (i < 0)
			i += p;
		if (j == p)
			j -= p;
	}

	for (i = 0; i<p; i++)
		for (j = 0; j<p; j++)
		{
			matrix[i][j] = M[i][j];
			matrix[i + p][j] = M[i][j] + 3 * p*p;
			matrix[i][j + p] = M[i][j] + 2 * p*p;
			matrix[i + p][j + p] = M[i][j] + p*p;
		}

	printMatrix(matrix, n);
	return;
}




void OddN(int n)
{
	vector<vector<int>>matr(n, vector<int>(n));
	int k = 1;
	int i = 0;
	int j = n / 2;
	int numofelm = n*n;
	for (int k = 1;k <= numofelm;k++)
	{
		matr[i][j] = k;
		i--;
		j++;
		if (k%n == 0)
		{
			i += 2;
			j--;
		}
		if (i < 0)
			i += n;
		if (j == n)
			j -= n;
	}

	printMatrix(matr, n);
	return;
}


void MakeMagic()
{
	int n;
	cout << "enter n" << endl;
	cin >> n;
	if (n <= 2)
	{
		cout << "enter another n" << endl;
		cin >> n;
	}
	if (n % 2 == 0)
	{
		if (n % 4 == 0)
			DoublyEven(n);
		else
			SinglyEven(n);
	}
	else
		OddN(n);
	return;
}


int main()
{
	int choice;
	cout << "1.Is magic or not?		2.Making a magic cube" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << endl << IsMagic() << endl;
		break;
	case 2:
		MakeMagic();
		break;
	default:
		cout << "exit game" << endl;
		break;
	};
	return 0;
}