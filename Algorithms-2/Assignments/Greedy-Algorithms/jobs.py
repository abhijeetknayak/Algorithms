class job:
    def __init__(self, weight=None, length=None, algorithm='diff'):
        self.weight = weight
        self.length = length
        self.algorithm = algorithm
        if weight is None or length is None:
            self.val = None
        else:
            if self.algorithm is 'diff':
                self.val = weight - length
            else:
                self.algorithm = weight / length

    def store_params(self, w, l, a):
        self.weight = w
        self.length = l

        if a is 'diff':
            self.val = w - l
        else:
            self.val = w / l


def process_file(fp, algorithm):
    n = int(fp.readline())
    out = []
    for i in range(n):
        line = [int(x) for x in fp.readline().split(' ')]
        obj = job()
        obj.store_params(line[0], line[1], algorithm)
        out.append(obj)

    sorted_jobs = sort_jobs(out)

    return sorted_jobs

def sort_function(sorted_jobs, job_obj):
    if sorted_jobs is None:
        sorted_jobs = [job_obj]
        return sorted_jobs
    else:
        temp = sorted_jobs.copy()
        for idx, j in enumerate(sorted_jobs):
            if job_obj.val > j.val:  # New object has a higher value
                temp.insert(idx, job_obj)  # Insert new job at index idx
                break
            elif job_obj.val == j.val:  # Compare weights now to break ties
                if job_obj.weight > j.weight:
                    temp.insert(idx, job_obj)
                    break
                else:
                    if idx == len(sorted_jobs) - 1:  # Last index reached. Need to add new object to the list
                        temp.insert(idx + 1, job_obj)
                        break
                    continue
            else:  # Val of new object is smaller
                if idx == len(sorted_jobs) - 1:  # Last index reached, Have to add new object at end of list
                    temp.insert(idx + 1, job_obj)
                else:
                    continue
    return temp

def sort_jobs(jobs_list):
    sorted_jobs = None
    for idx, obj in enumerate(jobs_list):
        sorted_jobs = sort_function(sorted_jobs, obj)
    return sorted_jobs

def get_total_cost(job_list):
    completion_time = 0
    cost = 0
    for idx in range(len(job_list)):
        completion_time += job_list[idx].length
        cost += job_list[idx].weight * completion_time

    return cost

if __name__ == '__main__':
    fp = open('jobs.txt')
    sorted_jobs = process_file(fp, 'diff')
    print(get_total_cost(sorted_jobs))
    fp.close()

    fp = open('jobs.txt')
    sorted_jobs = process_file(fp, 'div')
    print(get_total_cost(sorted_jobs))
    fp.close()

    l = [job(8, 50), job(74, 59), job(31, 73), job(45, 79), job(24, 10),
         job(41, 66), job(93, 43), job(88, 4), job(20, 62)]
    sorted_jobs = sort_jobs(l)
    for j in sorted_jobs:
        print(j.weight, j.length, j.val)