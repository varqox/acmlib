// liczy a^(-1) modulo mod
LL inv(LL a, LL mod) {
	return 1 < a ? mod - inv(mod % a, a) * mod / a : 1;
}