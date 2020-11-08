#include <cstdio>
#include <cstring>

struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {
    bign result;
    result.len = strlen(str);
    for(int i = 0; i < result.len; i++) {
        result.d[i] = str[result.len - i - 1] - '0';
    }
    return result;
}

void showBign(bign a) {
    for(int i = a.len - 1; i >= 0; i--) {
        printf("%d", a.d[i]);
    }
}

bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry) {
        c.d[c.len++] = carry;
    }
    return c;
}

bign sub(bign a, bign b) {
    bign c;
    for(int i = 0; i < a.len || i < b.len; i++) {
        if(a.d[i] < b.d[i]) {
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

bign multi(bign a, int b) {
    bign c;
    int carry = 0;
    for(int i = 0; i < a.len; i++) {
        int temp = a.d[i] * b + temp;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry) {
        c.d[c.len++] = carry;
    }
    return c;
}

bign divide(bign a, int b, int& r) {
    bign c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--) {
        r = r * 10 + a.d[i];
        if(r < b) {
            c.d[i] = 0;
        }
        else {
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}

int main() {
    char strA[10] = "123456789";
    char strB[10] = "321";
    bign a = change(strA);
    bign b = change(strB);
    int c = 321;
    //add
    showBign(add(a, b));
    printf("\n");
    //sub
    showBign(sub(a, b));
    printf("\n");
    //multi
    showBign(multi(a, c));
    printf("\n");
    //divide
    int r = 0;
    showBign(divide(a, c, r));
    printf("\n");

    return 0;
}