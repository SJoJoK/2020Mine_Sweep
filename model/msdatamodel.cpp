#include "msdatamodel.h"

MSDataModel::MSDataModel():b(std::make_shared<Block>(8,8,10))
{

}

std::shared_ptr<Block> MSDataModel :: get_block() throw()
{
    return b;
}
bool MSDataModel :: restart(int row, int col, int boom_num)
{
    b->re_construct(row, col, boom_num);
    Fire_OnPropertyChanged("restart_block");
    return true;
}
bool MSDataModel::leftblock(int x_pos, int y_pos){
    //ccx 7.11
    //left->boom,lose
    if(b->p[x_pos][y_pos].get_boom()==1){
		b->set_play(false);
		b->set_lose(true);
        Fire_OnPropertyChanged("lose");
		b->set_lock(true);
        return true;
    }
    b->bset_show(x_pos, y_pos);
    b->reset_visit(x_pos, y_pos);
    qDebug()<<b->p[x_pos][y_pos].show_info();
    Fire_OnPropertyChanged("block");
    return true;
}
//ccx 7.11
bool MSDataModel::rightblock(int x_pos, int y_pos){
    //change states of flag/mark
    if(b->p[x_pos][y_pos].get_show()==0){
        //00->10
        if(b->p[x_pos][y_pos].get_flag()==0 && b->p[x_pos][y_pos].get_mark()==0){
            b->p[x_pos][y_pos].set_flag(1);
            b->p[x_pos][y_pos].set_mark(0);
            b->change_flag_num(1);
        }
        //10->01
        else if(b->p[x_pos][y_pos].get_flag()==1 && b->p[x_pos][y_pos].get_mark()==0){
            b->p[x_pos][y_pos].set_flag(0);
            b->p[x_pos][y_pos].set_mark(1);
            b->change_flag_num(-1);
        }
        //01->00
        else if(b->p[x_pos][y_pos].get_flag()==0 && b->p[x_pos][y_pos].get_mark()==1){
            b->p[x_pos][y_pos].set_flag(0);
            b->p[x_pos][y_pos].set_mark(0);
        }
        //ccx 7.12 change current flag number
		qDebug() << b->p[x_pos][y_pos].show_info();
		Fire_OnPropertyChanged("block");
    }

    //win(flag/boom onetoone)
    int cnt=0;//count number of is_flag&&is_boom
    for(int i=0; i<b->get_row(); i++){
        for(int j=0; j<b->get_col(); j++){
            if(b->p[i][j].get_boom() && b->p[i][j].get_flag() ) cnt++;
        }
    }
    //win
    if(cnt==b->get_boom_num()){
		b->set_play(false);
		b->set_win(true);
        Fire_OnPropertyChanged("win");
		b->set_lock(true);
        //return true;
    }
    return true;
}

//ccx 7.13
bool MSDataModel::resetblock(SETTING setting, int row, int col, int boom_num){
    if(setting == JUNIOR){
        b->re_construct(8,8,10);
        b->set_setting(JUNIOR);
    }
    if(setting == MIDDLE){
        b->re_construct(16,16,40);
        b->set_setting(MIDDLE);
    }
    if(setting == SENIOR){
        b->re_construct(16,32,99);
        b->set_setting(SENIOR);
    }
    if(setting == CUSTOM){
        b->re_construct(row, col, boom_num);
        b->set_setting(CUSTOM);
    }
    Fire_OnPropertyChanged("restart_block");
	return true;
}

//ccx 7.13
bool MSDataModel::rankadd(UserParameter userinfo){
    //construct vector
    std::vector<UserParameter> userrank;
    userrank.push_back(userinfo);

    if(b->get_setting()==JUNIOR){
        std::ifstream file1("JUNIOR");
        if(!file1){
            qDebug()<<"read file error!";
        }
        else{
            while(file1>>userinfo.name && file1>>userinfo.time){
                userrank.push_back(userinfo);
            }
        }
        sort(userrank.begin(),userrank.end(),sort_stol);
        file1.close();//read finished

        std::ofstream file2("JUNIOR");
        if(!file2){
            qDebug()<<"write file error!";
        }
        else{
            for(std::vector<UserParameter>::iterator iter=userrank.begin(); iter != userrank.end(); iter++){
                file2<<iter->name<<' '<<iter->time<<std::endl;
            }
        }
        file2.close();//write finished
    }

    if(b->get_setting()==MIDDLE){
        std::ifstream file1("MIDDLE");
        if(!file1){
            qDebug()<<"read file error!";
        }
        else{
            while(file1>>userinfo.name && file1>>userinfo.time){
                userrank.push_back(userinfo);
            }
        }
        sort(userrank.begin(),userrank.end(),sort_stol);
        file1.close();//read finished

        std::ofstream file2("MIDDLE");
        if(!file2){
            qDebug()<<"write file error!";
        }
        else{
            for(std::vector<UserParameter>::iterator iter=userrank.begin(); iter != userrank.end(); iter++){
                file2<<iter->name<<' '<<iter->time<<std::endl;
            }
        }
        file2.close();//write finished
    }

    if(b->get_setting()==SENIOR){
        std::ifstream file1("SENIOR");
        if(!file1){
            qDebug()<<"read file error!";
        }
        else{
            while(file1>>userinfo.name && file1>>userinfo.time){
                userrank.push_back(userinfo);
            }
        }
        sort(userrank.begin(),userrank.end(),sort_stol);
        file1.close();//read finished

        std::ofstream file2("SENIOR");
        if(!file2){
            qDebug()<<"write file error!";
        }
        else{
            for(std::vector<UserParameter>::iterator iter=userrank.begin(); iter != userrank.end(); iter++){
                file2<<iter->name<<' '<<iter->time<<std::endl;
            }
        }
        file2.close();//write finished
    }
    return 0;
}
