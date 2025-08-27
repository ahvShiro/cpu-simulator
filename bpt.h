typedef struct{
    int address;
    int pc;
    int taken;
    int prediction;
    int hits;
    int miss;
} bpt;

void main(){
    bpt bpt;
    branch_predictor(bpt);
    
}

void branch_predictor(bpt bpt){

}
