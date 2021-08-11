class MyStack

{

  private:

	queue<int> q;

  public:

	void push(int n)

	{

		queue<int> tmp;

		tmp.push(n);

		while (!q.empty())

		{

			tmp.push(q.front());

			q.pop();

		}

		queue<int> fk = q;

		q = tmp;

		tmp = fk;

	}
    int pop()

	{
        int g=q.front();
		q.pop();
        return g;
	}

	int top()

	{

		return q.front();

	}

	bool empty()

	{

		return q.empty();

	}
};