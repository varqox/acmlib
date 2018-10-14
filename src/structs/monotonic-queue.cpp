struct Mxque {
	deque<PII> dq;
	
	void add(int val) {
		int il = 1;
		while (!dq.empty() && dq.back().X <= val) {
			il += dq.back().Y;
			dq.pop_back();
		}
		dq.EB(val, il);
	}
	
	void pop() {
		dq.front().Y--;
		if(dq.front().Y == 0)
			dq.pop_front();
	}
	
	int getMax() {
		return dq.front().X;
	}
};