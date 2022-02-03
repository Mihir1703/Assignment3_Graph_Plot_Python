from matplotlib import pyplot as p
plot = []

with open('output.txt','r+') as f:
    data = f.read()
    data =data.splitlines()
    for i in data:
        x_axis = i.split(' ')
        x_axis.remove('')
        for j in range(len(x_axis)):
            x_axis[j] = int(x_axis[j])
        plot.append(x_axis)

p.plot(plot[0],plot[1],label="binary search")
p.plot(plot[0],plot[2],label="ternary search")
p.xlabel(f'Search value (input size : {len(plot[0])})')
p.ylabel('Comparison count')
p.legend()
p.grid()
p.savefig(r'graph.jpeg')