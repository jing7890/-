#define LossAndSplit(x,y):
    //我们用 x 来表示训练数据
    // 我们用 y 来表示训练数据的label
    // x[i]表示训练数据的第i个特征
    // x_i 表示第i个训练样本
     // minLoss 表示最小的损失
    minLoss = Integet.max_value
    // feature 表示是训练的数据第几纬度的特征
    feature = 0
    // split 表示切分点的个数
    split = 0

    // M 表示 样本x的特征个数
    for j in range(0,M):
        // 该维特征下，特征值的每个切分点，这里具体的切分方式可以自己定义
        for c in range(0,x[j]):
            L = 0
            //第一类
            R1 = {x|x[j] <= c}
            // 第二类
            R2 = {x|x[j] > c}
            // 属于第一类样本的y值的平均值
            y1 = ave{y|x 属于 R1}
            // 属于第二类样本的y值的平均值
            y2 = ave{y| x 属于 R2}
            // 遍历所有的样本，找到 loss funtion 的值
            for x_1 in all x
                if x_1 属于 R1：
                    L += (y_1 - y1)^2
                else:
                    L += (y_1 - y2)^2
            if L < minLoss:
               minLoss = L
               feature  = i
               split = c
    return minLoss,feature ,split
// 定义训练数据
train_data = [[5.1,3.5,1.4,0.2],[4.9,3.0,1.4,0.2],[7.0,3.2,4.7,1.4],[6.4,3.2,4.5,1.5],[6.3,3.3,6.0,2.5],[5.8,2.7,5.1,1.9]]

// 定义label
label_data = [[1,0,0],[1,0,0],[0,1,0],[0,1,0],[0,0,1],[0,0,1]]
// index 表示的第几类
def findBestLossAndSplit(train_data,label_data,index):
        sample_numbers = len(label_data)
        feature_numbers = len(train_data[0])
        current_label = []

        # define the minLoss
        minLoss = 10000000

        # feature represents the dimensions of the feature
        feature = 0

        # split represents the detail split value
        split = 0

        # get current label
        for label_index in range(0,len(label_data)):
            current_label.append(label_data[label_index][index])

        # trans all features
        for feature_index in range(0,feature_numbers):
            ## current feature value
            current_value = []

            for sample_index in range(0,sample_numbers):
                current_value.append(train_data[sample_index][feature_index])
            L = 0
            ## different split value
            print current_value
            for index in range(0,len(current_value)):
                R1 = []
                R2 = []
                y1 = 0
                y2 = 0

                for index_1 in range(0,len(current_value)):
                    if current_value[index_1] < current_value[index]:
                        R1.append(index_1)
                    else:
                        R2.append(index_1)

                ## calculate the samples for first class
                sum_y = 0
                for index_R1 in R1:
                    sum_y += current_label[index_R1]
                if len(R1) != 0:
                    y1 = float(sum_y) / float(len(R1))
                else:
                    y1 = 0

                ## calculate the samples for second class
                sum_y = 0
                for index_R2 in R2:
                    sum_y += current_label[index_R2]
                if len(R2) != 0:
                    y2 = float(sum_y) / float(len(R2))
                else:
                    y2 = 0

                ## trans all samples to find minium loss and best split
                for index_2 in range(0,len(current_value)):
                    if index_2 in R1:
                        L += float((current_label[index_2]-y1))*float((current_label[index_2]-y1))
                    else:
                        L += float((current_label[index_2]-y2))*float((current_label[index_2]-y2))

                if L < minLoss:
                    feature = feature_index
                    split = current_value[index]
                    minLoss = L
                    print "minLoss"
                    print minLoss
                    print "split"
                    print split
                    print "feature"
                    print feature
        return minLoss,split,feature

findBestLossAndSplit(train_data,label_data,0)

