def powmod(x, n, m):
    if n == 0: return 1
    if n == 1: return x % m;
    half = powmod(x, n//2, m)
    if n & 1: return (half*half*x)%m
    else: return (half*half)%m

def modinv(a, m):
    # x = s*a + t*m and y = u*a + v*m
    s, t, u, v = 1, 0, 0, 1
    x, y = a, m

    while(y > 0):
        xd = y
        sd, td = u, v

        yd = x % y
        q = x // y
        ud = s - q*u
        vd = t - q*v

        x, y, s, t, u, v = xd, yd, sd, td, ud, vd

    if s < 0: s += m
    return s

if __name__ == '__main__':
    print(modinv(4, 7))

