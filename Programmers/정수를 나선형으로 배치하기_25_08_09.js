function solution(n) {
    const res = [];
    for (let i=0; i<n; i++) {
        const a = [];
        for (let j=0; j<n; j++) a.push(0);
        res.push(a);
    }
    
    let i=0, j=0, flag=0;
    for (let cnt=1; cnt<=n*n; ) {
        while (flag == 0 && j<n && res[i][j] == 0) res[i][j++] = cnt++;
        if (flag == 0) i++, j--;
        
        while (flag == 1 && i<n && res[i][j] == 0) res[i++][j] = cnt++;
        if (flag == 1) j--, i--;
        
        while (flag == 2 && j>=0 && res[i][j] == 0) res[i][j--] = cnt++;
        if (flag == 2) i--, j++;
        
        while (flag == 3 && i>=0 && res[i][j] == 0) res[i--][j] = cnt++;
        if (flag == 3) j++, i++;
        
        flag = (flag+1)%4;
    }
    
    return res;
}
