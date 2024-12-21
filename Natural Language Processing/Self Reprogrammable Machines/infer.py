# infer: v1 © 2024 Sadman Sakib Khan Promit
# 131 + 131 GB disk + memory
# , torch_dtype = torch.bfloat16
import torch
from transformers import AutoTokenizer, AutoModelForCausalLM, AutoConfig
from accelerate import init_empty_weights, load_checkpoint_and_dispatch
import time

model_path = "C:/Users/proom/.cache/huggingface/hub/models--nvidia--Llama-3.1-Nemotron-70B-Instruct-HF/snapshots/fac73d3507320ec1258620423469b4b38f88df6e/"
temp = "C:/temp"
tokenizer = AutoTokenizer.from_pretrained(model_path)
config = AutoConfig.from_pretrained(model_path)
MAX_LENGTH = 300

def main():
    input_text = input("prompt: ")
    with init_empty_weights():
        model = AutoModelForCausalLM.from_config(config)
    model = load_checkpoint_and_dispatch(
        model,
        checkpoint = model_path,
        device_map = "auto",
        offload_folder = temp,
        offload_state_dict = True,
        offload_buffers = True
    )
    inputs = tokenizer(input_text, return_tensors = "pt")
    inputs = inputs.to(model.device)
    start_time = time.time()
    output = model.generate(
        input_ids = inputs["input_ids"],
        attention_mask = inputs["attention_mask"],
        max_length = MAX_LENGTH,
        pad_token_id = tokenizer.pad_token_id,
        eos_token_id = tokenizer.eos_token_id,
    )
    end_time = time.time()
    execution_time = end_time - start_time
    text = tokenizer.decode(output[0], skip_special_tokens = True)
    print(f"[{text}] [{execution_time / MAX_LENGTH:.2f}]")
    with open("log.txt", "a") as file:
        file.write(f"[{input_text}] [{text}] [{execution_time / MAX_LENGTH:.2f}]")

if __name__ == "__main__":
    main()