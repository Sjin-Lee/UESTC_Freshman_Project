### 1、问题描述

1、使用 GYM 中的 cliffwalking（如图 1 所示）环境，具体描述如下： 

​      a. 智能体从起点 S 开始，打到终点 G 后仿真结束。 

​      b. 智能体在  踏入非 cliff 或终点 G 的方格时，获得 Reward=-1；踏入 cliff 时， 获得 Reward=-100。 

​      c. 智能体每一步可以选择向上/向下/向左/向右前进，前进碰到边界时智能体 保持原地不动，碰到 cliff 区域时，智能体返回起点 S。

![](C:\Users\Aaron Summers\Desktop\Cliffwalk.png)

2、根据上述条件设置状态空间以及动作空间。编写代码构建 Q-Table，使用 Qlearning 方法对智能体进行训练。 

3、编写 python 代码，使用 Sarsa 方法对智能体进行训练。 

4、考虑如何修改 reward 能够使得智能体倾向于走 Safer path 到达终点？并通过实验 验证。

## 2、解决方法

动作如下：

```
0: UP
1: RIGHT
2: DOWN
3: LEFT
```



#### 一、用Sarsa方法

![](C:\Users\Aaron Summers\Desktop\Sarsa.png)

定义Saras类

```python
class Sarsa(object):
    def __init__(self,o_dimension,a_dimension,LearningRate,Gama,Epsilon_greed):
        self.lr=LearningRate
        self.Epsilon=Epsilon_greed
        self.Gama=Gama
        self.Q=np.zeros((o_dimension,a_dimension))
        self.dimension=a_dimension
```

参数设置如下

```python
agent=Sarsa(
    o_dimension=env.observation_space.n,
    a_dimension=env.action_space.n,
    LearningRate=0.1,
    Gama=0.9,
    Epsilon_greed=0.1
)
```



#### 二、用Qlearning方法

![Qlearning](C:\Users\Aaron Summers\Desktop\Qlearning.png)

定义Qlearning类

```python
class QLearning(object):
    def __init__(self,o_dimension,a_dimension,LearningRate,Gama,Epsilon_greed):
        self.lr=LearningRate#学习率
        self.Epsilon=Epsilon_greed#按概率选择动作
        self.Gama=Gama#衰减率
        self.Q=np.zeros((o_dimension,a_dimension))
        self.dimension=a_dimension
```

参数设置如下：

```python
agent=QLearning(
    o_dimension=env.observation_space.n,
    a_dimension=env.action_space.n,
    LearningRate=0.1,
    Gama=0.9,
    Epsilon_greed=0.1
)
```

#### 修改Reward

为达到倾向于走Safer path,可以修改reward，设置为越远离悬崖，Reward越高，反之，越低。



### 3、结果展示

如.pynb文件所示，无论是Q-learning，还是Sarsa方法，结果都是随着epsilon进行，所用步数逐渐减小，总回报逐渐变大。但是Sarsa的测试结果都比Q-learning的要差，而路线则相对安全。

通过修改Reward，得到的最终策略为

```
[0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2]
```

总回报为-26，总步数为17