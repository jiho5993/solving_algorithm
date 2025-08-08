function solution(arr, queries) {
    queries.forEach(([a, b]) => {
        for (let i=a; i<=b; i++) arr[i]++;
    });
    
    return arr;
}
