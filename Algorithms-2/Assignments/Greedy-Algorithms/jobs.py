class job:
    def __init__(self, weight=None, length=None):
        self.weight = weight
        self.length = length
        if weight is None or length is None:
            self.val = None
        else:
            self.val = weight - length

    def store_params(self, w, l):
        self.weight = w
        self.length = l
        self.val = w - l

def process_file(fp, algorithm):
    n = int(fp.readline())
    out = []
    for i in range(n):
        line = [int(x) for x in fp.readline().split(' ')]
        obj = job()
        obj.store_params(line[0], line[1])
        out.append(obj)

def sort_function(sorted_jobs, job_obj):
    if sorted_jobs is None:
        sorted_jobs = [job_obj]
    else:
        for idx, j in enumerate(sorted_jobs):
            if job_obj.val > j.val:  # New object has a higher value
                sorted_jobs.insert(idx, job_obj)  # Insert new job at index idx
                break
            elif job_obj.val == j.val:  # Compare weights now to break ties
                if job_obj.weight > j.weight:
                    sorted_jobs.insert(idx, job_obj)
                    break
                else:
                    continue
            else:  # Val of new object is smaller
                if idx == len(sorted_jobs) - 1:  # Last index reached, Have to add new object at end of list
                    sorted_jobs.insert(idx + 1, j)
                else:
                    continue

def sort_jobs(jobs_list):
    sorted_jobs = None
    for obj in jobs_list:
        sort_function(sorted_jobs, obj)


if __name__ == '__main__':
    fp = open('jobs.txt')
    print(process_file(fp, 'diff'))