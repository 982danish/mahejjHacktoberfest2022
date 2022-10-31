
using System;
using System.Collections.Generic;

class GFG {
static List<int> arr = new List<int>();
static Dictionary<List<int>, int> memo
	= new Dictionary<List<int>, int>();
static int n = 0;

static int solve(int i, int j)
{
	if ((i > j) || (i >= n) || (j < 0))
	return 0;

	List<int> k = new List<int>{ i, j };
	if (memo.ContainsKey(k))
	return memo[k];

	int option1 = arr[i]
	+ Math.Min(solve(i + 2, j),
				solve(i + 1, j - 1));

	int option2 = arr[j]
	+ Math.Min(solve(i + 1, j - 1),
				solve(i, j - 2));

	memo[k] = Math.Max(option1, option2);
	return memo[k];
}

static int optimalStrategyOfGame()
{

	memo.Clear();
	return solve(0, n - 1);
}

public static void Main(string[] args)
{
	arr.Add(8);
	arr.Add(15);
	arr.Add(3);
	arr.Add(7);
	n = arr.Count;
	Console.WriteLine(optimalStrategyOfGame());

	arr.Clear();
	arr.Add(2);
	arr.Add(2);
	arr.Add(2);
	arr.Add(2);
	n = arr.Count;
	Console.WriteLine(optimalStrategyOfGame());

	arr.Clear();
	arr.Add(20);
	arr.Add(30);
	arr.Add(2);
	arr.Add(2);
	arr.Add(2);
	arr.Add(10);
	n = arr.Count;
	Console.WriteLine(optimalStrategyOfGame());
}
}

