# infer_disk: v3 © 2024 Sadman Sakib Khan Promit
# "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF" 131 GB
# "nvidia/Mistral-NeMo-Minitron-8B-Base" 15.6 GB
# "google/gemma-7b"
# "microsoft/phi-2" 5.18 GB
from transformers import AutoTokenizer, AutoModelForCausalLM, AutoConfig
from accelerate import init_empty_weights, load_checkpoint_and_dispatch
import time

model_path = "C:/Users/proom/.cache/huggingface/hub/models--nvidia--Llama-3.1-Nemotron-70B-Instruct-HF/snapshots/fac73d3507320ec1258620423469b4b38f88df6e/"
temp = "C:/temp"

def main():
    start_time = time.time()
    config = AutoConfig.from_pretrained(model_path)
    tokenizer = AutoTokenizer.from_pretrained(model_path)
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
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"[loading: {execution_time / 60:.2f}m]")
    while True:
        input_text = input("prompt: ")
        MAX_LENGTH = int(input("token: "))
        inputs = tokenizer(input_text, return_tensors = "pt")
        inputs = inputs.to(model.device)
        start_time = time.time()
        output = model.generate(
            input_ids = inputs["input_ids"],
            attention_mask = inputs["attention_mask"],
            max_new_tokens = MAX_LENGTH,
            do_sample = True,
            top_k = 50,
            top_p = 0.95,
            pad_token_id = tokenizer.pad_token_id,
            eos_token_id = tokenizer.eos_token_id,
        )
        end_time = time.time()
        execution_time = end_time - start_time
        generated_ids = output[:, inputs["input_ids"].shape[-1]:]
        output_text = tokenizer.decode(generated_ids[0], skip_special_tokens = True).strip()
        print(f"[{output_text}]")
        try:
            with open("70Binfer_log.txt", "a") as file:
                file.write(f"[{input_text}] [{output_text}] [{MAX_LENGTH} * {execution_time / MAX_LENGTH / 60:.2f} = {execution_time / 60:.2f}m]\n")
        except Exception as e:
            print(f"[{MAX_LENGTH} * {execution_time / MAX_LENGTH / 60:.2f} = {execution_time / 60:.2f}m]")

if __name__ == "__main__":
    main()