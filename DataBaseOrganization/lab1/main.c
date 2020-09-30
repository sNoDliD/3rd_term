#pragma ide diagnostic ignored "OCDFAInspection"
#pragma ide diagnostic ignored "cert-err34-c"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "bugprone-macro-parentheses"
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    int first_result_pos;
} Student;

typedef struct {
    int term_num;
    char subject[30];
    int grade;
    int next_result_pos;
} Results;

typedef struct {
    int key;
    int pos;
} Index;

#define I_SIZE  sizeof(Index)
#define S_SIZE  sizeof(Student)
#define R_SIZE  sizeof(Results)
#define INVALID -100

#define STUDENT_DONT_EXIST(out) fprintf(out, "Student doesn't exist\n\n"); \
                                continue;

#define STUDENT_ENTER_ID(out, key)  fprintf(out, "Enter student id:\n");\
                                    fscanf(in, "%d", &key);\
                                    \
                                    if (!is_key(key)) { \
                                    STUDENT_DONT_EXIST(out);\
                                    }

#pragma region DECLARATION

int res_num_by_key(int key);

#pragma endregion


#pragma region INDEX

int num_of_inds() {
    FILE *f = fopen("M.ind", "rb");
    Index res;
    fread(&res, I_SIZE, 1, f);
    fclose(f);
    return res.key;
}

Index get_ind_by_pos(int pos) {
    FILE *f = fopen("M.ind", "rb");
    Index res = {-1, -1};
    fseek(f, (pos + 1) * I_SIZE, SEEK_SET);
    fread(&res, I_SIZE, 1, f);
    fclose(f);
    return res;
}

Index get_ind_by_key(int key) {
    int l = 0;
    int r = num_of_inds() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        Index temp = get_ind_by_pos(m);
        if (temp.key == key)
            return temp;
        if (temp.key < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return (Index) {-1, -1};
}

int is_key(int key) {
    Index ind = get_ind_by_key(key);
    return (ind.key > 0 || ind.pos > 0);
}

int ind_pos_by_key(int key) {
    int l = 0;
    int r = num_of_inds() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        Index temp = get_ind_by_pos(m);
        if (temp.key == key)
            return m;
        if (temp.key < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -5;
}

#pragma endregion


#pragma region GET

Student get_stud_by_pos(int pos) {
    FILE *f = fopen("M.fl", "rb");
    Student res = {-1, "\0", -1};
    fseek(f, pos * S_SIZE, SEEK_SET);
    fread(&res, S_SIZE, 1, f);
    fclose(f);
    return res;
}

Student get_stud_by_key(int key) {
    Index ind = get_ind_by_key(key);
    Student res = get_stud_by_pos(ind.pos);
    return res;
}

Results get_res_by_pos(int pos) {
    FILE *f = fopen("S.fl", "rb");
    Results res;
    fseek(f, (pos + 1) * R_SIZE, SEEK_SET);
    fread(&res, R_SIZE, 1, f);
    fclose(f);
    return res;
}

Results get_res_by_args(int key, const char *subj, int term) {
    Student student = get_stud_by_key(key);
    Results cur = get_res_by_pos(student.first_result_pos);
    int ret = 1;
    while (cur.term_num != term || strcmp(subj, cur.subject) != 0) {
        if (cur.next_result_pos > 0)
            cur = get_res_by_pos(cur.next_result_pos);
        else {
            ret = 0;
            break;
        }
    }
    if (!ret)
        cur.grade = INVALID;
    return cur;
}

int get_res_pos(int key, const char *subj, int term) {
    Student student = get_stud_by_key(key);
    Results cur = get_res_by_pos(student.first_result_pos);
    int ret = student.first_result_pos;
    while (cur.term_num != term || strcmp(subj, cur.subject) != 0) {
        if (cur.next_result_pos > 0) {
            ret = cur.next_result_pos;
            cur = get_res_by_pos(cur.next_result_pos);
        } else {
            return INVALID;
        }
    }
    return ret;
}

#pragma endregion


#pragma region UPDATE

void edit_stud_by_pos(int pos, Student stud) {
    FILE *f = fopen("M.fl", "rb+");
    fseek(f, pos * S_SIZE, SEEK_SET);
    fwrite(&stud, S_SIZE, 1, f);
    fclose(f);
}

void edit_ind_by_pos(int pos, Index ind) {
    FILE *f = fopen("M.ind", "rb+");
    fseek(f, (pos + 1) * I_SIZE, SEEK_SET);
    fwrite(&ind, I_SIZE, 1, f);
    fclose(f);
}

void edit_res_by_pos(int pos, Results p) {
    FILE *f = fopen("S.fl", "rb+");
    fseek(f, (pos + 1) * R_SIZE, SEEK_SET);
    fwrite(&p, R_SIZE, 1, f);
    fclose(f);
}

#pragma endregion


#pragma region DELTE

void del_res_by_args(int key, const char *subj, int term) {
    Student student = get_stud_by_key(key);
    Results del = get_res_by_args(key, subj, term);
    int del_pos = student.first_result_pos;
    int prev_pos = del_pos;
    while (get_res_by_pos(del_pos).term_num != term || strcmp(subj, get_res_by_pos(del_pos).subject) != 0) {
        prev_pos = del_pos;
        del_pos = get_res_by_pos(del_pos).next_result_pos;
    }
    if (prev_pos != del_pos) {
        Results prev_res = get_res_by_pos(prev_pos);
        prev_res.next_result_pos = del.next_result_pos;
        edit_res_by_pos(prev_pos, prev_res);
    } else {
        student.first_result_pos = del.next_result_pos;
        edit_stud_by_pos(get_ind_by_key(key).pos, student);
    }

    Results info = get_res_by_pos(-1);
    del.next_result_pos = info.next_result_pos;
    info.next_result_pos = del_pos;
    --info.grade;
    edit_res_by_pos(del_pos, del);
    edit_res_by_pos(-1, info);
}

void del_all_res_by_key(int key) {
    Student stud = get_stud_by_key(key);
    Results res = get_res_by_pos(stud.first_result_pos);
    Results info = get_res_by_pos(-1);
    int empty_pos = info.next_result_pos;
    info.next_result_pos = stud.first_result_pos;
    info.grade = info.grade - res_num_by_key(key);
    edit_res_by_pos(-1, info);
    int pos = stud.first_result_pos;
    stud.first_result_pos = -5;
    edit_stud_by_pos(get_ind_by_key(key).pos, stud);
    while (res.next_result_pos >= 0) {
        pos = res.next_result_pos;
        res = get_res_by_pos(res.next_result_pos);
    }
    res.next_result_pos = empty_pos;
    edit_res_by_pos(pos, res);
}

void files_clear() {
    FILE *s_ind, *s_fl, *p_fl;
    s_ind = fopen("M.ind", "wb");
    Index ind = {0, 0};
    fwrite(&ind, I_SIZE, 1, s_ind);
    fclose(s_ind);

    s_fl = fopen("M.fl", "wb");
    fclose(s_fl);

    p_fl = fopen("S.fl", "wb");
    Results info = {0, "\0", 0,  0};
    fwrite(&info, R_SIZE, 1, p_fl);
    fclose(p_fl);
}


int del_stud_by_key(int key) {
    Index del = get_ind_by_key(key);
    if (del.key != key)
        return 0;
    Index info = get_ind_by_pos(-1);
    if(info.key == 1){
        files_clear();
        return 1;
    }
    Student last_stud = get_stud_by_pos(num_of_inds() - 1);
    if (get_stud_by_key(key).first_result_pos >= 0)
        del_all_res_by_key(key);
    edit_stud_by_pos(del.pos, last_stud);
    Index last = get_ind_by_key(last_stud.id);
    last.pos = del.pos;
    edit_ind_by_pos(ind_pos_by_key(last.key), last);
    int new_size = --info.key;
    edit_ind_by_pos(-1, info);
    int del_pos = ind_pos_by_key(del.key);
    while (del_pos < new_size) {
        edit_ind_by_pos(del_pos, get_ind_by_pos(del_pos + 1));
        ++del_pos;
    }
    return 1;
}

#pragma endregion


#pragma region INSERT

int insert_index(Index ind) {
    int l = 0;
    int r = num_of_inds() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        Index temp = get_ind_by_pos(m);
        if (temp.key == ind.key) {
            break;
        }
        if (temp.key < ind.key)
            l = m + 1;
        else
            r = m - 1;
    }
    if (r > l) {
        return 0;
    }
    int insert_pos = l;
    int cur = num_of_inds();
    while (cur > insert_pos) {
        edit_ind_by_pos(cur, get_ind_by_pos(cur - 1));
        --cur;
    }
    edit_ind_by_pos(cur, ind);
    Index info = get_ind_by_pos(-1);
    ++info.key;
    edit_ind_by_pos(-1, info);
    return 1;
}

int insert_student(Student stud) {
    Index ind = {stud.id, num_of_inds()};
    if (!insert_index(ind)) {
        return 0;
    }
    edit_stud_by_pos(ind.pos, stud);
    return 1;
}

int insert_res_by_key(int key, Results res) {
    if (!is_key(key)) {
        return 0;
    }
    Results prev;
    Student stud = get_stud_by_key(key);
    int prev_pos = stud.first_result_pos;
    Results info = get_res_by_pos(-1);
    int insert_pos = info.next_result_pos;
    if (stud.first_result_pos < 0) {
        stud.first_result_pos = insert_pos;
        edit_stud_by_pos(get_ind_by_key(key).pos, stud);
    }
    else {
        prev = get_res_by_pos(stud.first_result_pos);
        while (prev.next_result_pos >= 0) {
            prev_pos = prev.next_result_pos;
            prev = get_res_by_pos(prev.next_result_pos);
        }
        prev.next_result_pos = info.next_result_pos;
        edit_res_by_pos(prev_pos, prev);
    }

    if (info.grade == info.next_result_pos) {
        ++info.grade;
        ++info.next_result_pos;
    }
    else {
        info.next_result_pos = get_res_by_pos(insert_pos).next_result_pos;
    }
    edit_res_by_pos(insert_pos, res);
    edit_res_by_pos(-1, info);

    return 1;
}

#pragma endregion


#pragma region UT

void print_stud(FILE *out, Student stud) {
    fprintf(out, "%d - %s\n", stud.id, stud.name);
}

void print_res(FILE *out, Results res) {
    fprintf(out, "\t(%d - %d - %s)\n", res.term_num, res.grade, res.subject);
}

int num_of_res() {
    FILE *f = fopen("S.fl", "rb");
    Results info;
    fread(&info, R_SIZE, 1, f);
    fclose(f);

    return info.grade;
}

void print(FILE *out) {
    int siz = num_of_inds();
    int res_siz = num_of_res();
    fprintf(out, "Students: %d\nResults: %d\n", siz, res_siz);
    for (int i = 0; i < siz; ++i) {
        Index cur_ind = get_ind_by_pos(i);
        Student cur_stud = get_stud_by_pos(cur_ind.pos);
        print_stud(out, cur_stud);
        if (cur_stud.first_result_pos >= 0) {
            Results cur_res = get_res_by_pos(cur_stud.first_result_pos);
            for (int j = 0;; ++j) {
                print_res(out, cur_res);
                if (cur_res.next_result_pos > 0) {
                    cur_res = get_res_by_pos(cur_res.next_result_pos);
                } else break;
            }
        }
    }
    fprintf(out, "\n\n");
}

#pragma endregion


#pragma region other

int res_num_by_key(int key) {
    if (!is_key(key))
        return -1;
    int pos = get_stud_by_key(key).first_result_pos;
    int res = 0;
    while (pos >= 0) {
        pos = get_res_by_pos(pos).next_result_pos;
        ++res;
    }
    return res;
}

void help(FILE *out) {
    fprintf(out, "insert_m\t-\tInsert student\n");
    fprintf(out, "insert_s\t-\tInsert result\n");
    fprintf(out, "get_m\t\t-\tFind student\n");
    fprintf(out, "get_s\t\t-\tFind result\n");
    fprintf(out, "update_m\t-\tUpdate student\n");
    fprintf(out, "update_s\t-\tUpdate result\n");
    fprintf(out, "del_m\t\t-\tDelete student\n");
    fprintf(out, "del_s\t\t-\tDelete result\n");
    fprintf(out, "print\t\t-\tPrint all students and resultes\n");
    fprintf(out, "end\t\t\t-\tClose program\n\n");
}

void files_init() {
    FILE *s_ind, *s_fl, *p_fl;
    s_ind = fopen("M.ind", "rb");
    if (!s_ind) {
        s_ind = fopen("M.ind", "wb");
        Index ind = {0, 0};
        fwrite(&ind, I_SIZE, 1, s_ind);
    }
    fclose(s_ind);

    s_fl = fopen("M.fl", "rb");
    if (!s_fl) {
        s_fl = fopen("M.fl", "wb");
    }
    fclose(s_fl);

    p_fl = fopen("S.fl", "rb");
    if (!p_fl) {
        p_fl = fopen("S.fl", "wb");
        Results info = {0, "\0", 0, 0};
        fwrite(&info, R_SIZE, 1, p_fl);
    }
    fclose(p_fl);
}

#pragma endregion


int main() {
    FILE *in = stdin;
    FILE *out = stdout;

    files_init();
    help(out);

    char cmd[30];

    while (1) {
        fscanf(in, "%s", cmd);

        if (strcasecmp(cmd, "insert_m") == 0) {
            Student student;

            fprintf(out, "Enter student id:\n");
            fscanf(in, "%d", &(student.id));

            if (is_key(student.id)) {
                fprintf(out, "Student is already exist\n\n");
                continue;
            }
            fprintf(out, "Enter name:\n");
            fscanf(in, "%s", student.name);

            student.first_result_pos = -5;
            insert_student(student);
            fprintf(out, "Success\n\n");
        }
        else if (strcasecmp(cmd, "insert_s") == 0) {
            Results result;
            int key;
            STUDENT_ENTER_ID(out, key);

            fprintf(out, "Enter subject:\n");
            fscanf(in, "%s", result.subject);
            fprintf(out, "Enter term:\n");
            fscanf(in, "%d", &(result.term_num));
            fprintf(out, "Enter grade:\n");
            fscanf(in, "%d", &(result.grade));

            result.next_result_pos = -5;
            insert_res_by_key(key, result);
            fprintf(out, "Success\n\n");
        }
        else if (strcasecmp(cmd, "get_m") == 0) {
            int key;
            fprintf(out, "Enter student id:\n");
            fscanf(in, "%d", &key);

            if (is_key(key)) {
                print_stud(out, get_stud_by_key(key));
                fprintf(out, "\n");
            }
            else {
                STUDENT_DONT_EXIST(out);
            }
        }
        else if (strcasecmp(cmd, "del_m") == 0) {
            int key;
            fprintf(out, "Enter student id:\n");
            fscanf(in, "%d", &key);
            if (is_key(key)) {
                del_stud_by_key(key);
                fprintf(out, "Success\n\n");
            }
            else {
                STUDENT_DONT_EXIST(out);
            }
        }
        else if (strcasecmp(cmd, "update_m") == 0) {
            int key;
            STUDENT_ENTER_ID(out, key);
            Student stud = get_stud_by_key(key);

            fprintf(out, "Enter new name:\n");
            fscanf(in, "%s", stud.name);

            edit_stud_by_pos(get_ind_by_key(key).pos, stud);
            fprintf(out, "Success\n\n");
        }
        else if (strcasecmp(cmd, "update_s") == 0) {
            int key;
            STUDENT_ENTER_ID(out, key);

            char subj[30];
            fprintf(out, "Enter subject:\n");
            fscanf(in, "%s", subj);

            int term;
            fprintf(out, "Enter term:\n");
            fscanf(in, "%d", &term);

            int pos = get_res_pos(key, subj, term);
            if (pos == INVALID) {
                fprintf(out, "This result doesn't exist\n\n");
                continue;
            }
            Results res = get_res_by_pos(pos);

            fprintf(out, "Enter new grade:\n");
            fscanf(in, "%d", &(res.grade));

            edit_res_by_pos(pos, res);
            fprintf(out, "Success\n\n");
        }
        else if (strcasecmp(cmd, "get_s") == 0) {
            int key;
            STUDENT_ENTER_ID(out, key);

            char subj[30];
            fprintf(out, "Enter subject:\n");
            fscanf(in, "%s", subj);

            int term;
            fprintf(out, "Enter term:\n");
            fscanf(in, "%d", &term);

            Results res = get_res_by_args(key, subj, term);
            if (res.grade == INVALID) {
                fprintf(out, "This result doesn't exist\n\n");
                continue;
            }

            print_stud(out, get_stud_by_key(key));
            print_res(out, res);
            fprintf(out, "\n");
        }
        else if (strcasecmp(cmd, "del_s") == 0) {
            int key;
            STUDENT_ENTER_ID(out, key);

            char subj[30];
            fprintf(out, "Enter subject:\n");
            fscanf(in, "%s", subj);

            int term;
            fprintf(out, "Enter term:\n");
            fscanf(in, "%d", &term);

            int pos = get_res_pos(key, subj, term);
            if (pos == INVALID) {
                fprintf(out, "This result doesn't exist\n\n");
                continue;
            }

            del_res_by_args(key, subj, term);
            fprintf(out, "Success\n\n");
        }
        else if (strcasecmp(cmd, "print") == 0) {
            print(out);
        }
        else if (strcasecmp(cmd, "end") == 0) {
            break;
        }
    }
    return 0;
}
