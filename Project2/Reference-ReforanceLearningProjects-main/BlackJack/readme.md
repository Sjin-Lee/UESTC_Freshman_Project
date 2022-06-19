## 1、问题描述

21点又名黑杰克（Blackjack），起源于法国，已流传到世界各地，有着悠久的历史。现在在世界各地的赌场中都可以看到二十一点，随着互联网的发展，二十一点开始走向网络时代。该游戏由2到6个人玩，使用除大小王之外的52张牌，游戏者的目标是使手中的牌的点数之和不超过21点且尽量大。

具体游戏规则可以参考https://baike.baidu.com/item/21%E7%82%B9/5481683

##### 一.使用首次访问蒙特卡罗方法，在 BlackJack 环境中对策略进行 on-policy 学习。 

要求： 

1.使用 Q-table 的形式存储状态-动作价值。

 2.使用 epsilon-greedy 策略对环境进行探索，epsilon 采用线性衰减的方式，随 episode 轮 数进行衰减。学习最优的 epsilon-greedy 策略。 

3.选择合适的轮数(episode 个数)、epsilon 的衰减范围和速度、reward 折损因子进行训 练，并进行 5000 轮测试统计胜率，注意测试时使用的策略。 

##### 二.使用 TD(1)方法，在 BlackJack 环境中对策略进行 off-policy 学习。

要求： 

1.使用 Q-table 的形式存储状态-动作价值。 

2.使用 epsilon-greedy 策略对环境进行探索，epsilon 采用线性衰减的方式，随 episode 轮 数进行衰减。学习最优的 greedy 策略 

3.选择合适的轮数(episode 个数)、epsilon 的衰减范围和速度、reward 折损因子、学习率 进行训练，并进行 5000 轮测试统计胜率，注意测试时使用的策略。

##  2、解决方法

MC算法的On-Policy可以在采样上改变

```python
def Sample(env,Q,epsilon,Policy=False):
    Obs,All_Reward,All_Actions=[],[],[]
    Obtion=env.reset()
    Obs.append(Obtion)
    Over=False
    while not Over:
        if Policy:
            Select_Action=random.randint(0,1)
        else:
            if random.random()>=epsilon:
                Select_Action=Greedy(Q,Obtion)
            else:
                Select_Action=random.randint(0, 1)
        Obtion,TheR,Over,_=env.step(Select_Action)
        if not Over:
            Obs.append(Obtion)
        All_Reward.append(TheR)
        All_Actions.append(Select_Action)
    return {'obs':Obs,'actions':All_Actions,'rewards':All_Reward}
```

通过设置epsilon的线性衰减，衰减范围为[0.05,0.95]，进行多轮测试

```python
epsilon=0
for i in range(20):
    epsilon=1-i*0.05
    Q=Compute_Q(env,epsilon,C_Num=5000)
    main(Q,epsilon)
```

## 3、结果展示

在MC—OnPolicy下，胜率随epsilon变化如下：

| epsilon | 1.0   | 0.95  | 0.9   | 0.85  | 0.80  | 0.75  | 0.70  | 0.65  | 0.60  | 0.55  | 0.50  | 0.45  | 0.4   | 0.35  | 0.3   | 0.25  | 0.2   | 0.15  | 0.1   | 0.05  |
| ------- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 胜率    | 0.281 | 0.299 | 0.295 | 0.299 | 0.311 | 0.318 | 0.328 | 0.322 | 0.347 | 0.343 | 0.346 | 0.357 | 0.361 | 0.376 | 0.361 | 0.371 | 0.382 | 0.374 | 0.386 | 0.379 |

## 4、项目总结

通过BlackJack项目，进一步了解了Mote-Carol算法的特性，解决了相关问题。