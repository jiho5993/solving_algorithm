class MinStack {

    public int[] stackArray;
    public int idx;
    public int minimumValue;

    /** initialize your data structure here. */
    public MinStack() {
        stackArray = new int[100001];
        for(int i=1; i<100001; i++) stackArray[i] = 0;
        idx = 0;
        minimumValue = Integer.MAX_VALUE;
    }

    public void push(int x) {
        stackArray[++idx] = x;
        minimumValue = Math.min(minimumValue, x);
    }

    public void pop() {
        this.idx--;
        minimumValue = Integer.MAX_VALUE;
        for(int i=1; i<=idx; i++)
            minimumValue = Math.min(minimumValue, stackArray[i]);
    }

    public int top() {
        return this.stackArray[idx];
    }

    public int getMin() {
        return this.minimumValue;
    }

}
