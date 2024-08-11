def test_fnc(x):
    evaluate = x * x
    return evaluate


H = test_fnc


def higher_func(arg_func, y):
    final_value = arg_func(y) * arg_func(y)
    return final_value


print(higher_func(H, 3))