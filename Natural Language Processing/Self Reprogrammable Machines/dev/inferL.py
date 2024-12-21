from airllm import AutoModel
import time

MAX_LENGTH = 25
MODEL_PATH = "C:/Users/proom/.cache/huggingface/hub/models--nvidia--Mistral-NeMo-Minitron-8B-Base/snapshots/cc94637b669b62c4829b1e0c3b9074fecd883b74"
model = AutoModel.from_pretrained(MODEL_PATH)
input_text = [
        'Hello there',
        #'I like',
    ]
input_tokens = model.tokenizer(input_text,
    return_tensors = "pt", 
    return_attention_mask = False, 
    truncation = True, 
    max_length = MAX_LENGTH, 
    padding = False)
start_time = time.time()
generation_output = model.generate(
    input_tokens['input_ids'].cuda(), 
    max_new_tokens = 20,
    use_cache = True,
    return_dict_in_generate = True)
output = model.tokenizer.decode(generation_output.sequences[0])
end_time = time.time()
print(output)
execution_time = end_time - start_time
print(f" [{execution_time / MAX_LENGTH:.2f}]")